/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:35:50 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 17:56:47 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	complex_in_range(t_complex c, t_fract *fractol)
{
	if (c.r < fractol->x_min || c.r > fractol->x_max
		|| c.i < fractol->y_min || c.i > fractol->y_max)
		return (0);
	return (1);
}

// void	iterations_buddha(t_pixel p, t_fract *fractol)
// {
// 	int			i;
// 	t_complex	c;
// 	t_complex	z;

// 	c.r = scale_int_to_double(p.x, get_ir(0, WIDTH * fractol->b_factor),
// 			get_dr(-2, 1));
// 	c.i = scale_int_to_double(p.y, get_ir(0, HEIGHT * fractol->b_factor),
// 			get_dr(1.5, -1.5));
// 	z.r = 0;
// 	z.i = 0;
// 	i = -1;
// 	while (++i < MAX_IT)
// 	{
// 		z = complex_add(complex_sqr(z), c);
// 		if (complex_in_range(z, fractol))
// 		{
// 			p.x = scale_double_to_int(z.r, get_dr(fractol->x_min, fractol->x_max),
// 					get_ir(0, WIDTH - 1));
// 			p.y = scale_double_to_int(z.i, get_dr(fractol->y_min, fractol->y_max),
// 					get_ir(0, HEIGHT - 1));
// 			fractol->buddha[p.y][p.x]++;
// 		}
// 		if (z.r * z.r + z.i * z.i > 4)
// 			break ;
// 	}
// }

void	iterations_buddha(t_pixel p, t_fract *fractol, int max_it, int pos)
{
	int			i;
	t_complex	c;
	t_complex	z;

	c.r = scale_int_to_double(p.x, get_ir(0, WIDTH),
			get_dr(fractol->x_min, fractol->x_max));
	c.i = scale_int_to_double(p.y, get_ir(0, HEIGHT),
			get_dr(fractol->y_min, fractol->y_max));
	z.r = 0;
	z.i = 0;
	i = -1;
	while (++i < max_it)
	{
		z = complex_add(complex_sqr(z), c);
		p.x = scale_double_to_int(z.r, get_dr(fractol->x_min, fractol->x_max),
				get_ir(0, WIDTH - 1));
		p.y = scale_double_to_int(z.i, get_dr(fractol->y_min, fractol->y_max),
				get_ir(0, HEIGHT - 1));
		if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
			fractol->buddha[p.y][p.x][pos]++;
		if (z.r * z.r + z.i * z.i > 4)
			break ;
	}
}

int	get_buddha_max(t_fract *fractol, int pos)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			if (fractol->buddha[i][j][pos] > max)
				max = fractol->buddha[i][j][pos];
	}
	return (max);
}

int add_rgb(int color, int color2)
{
	t_rgb	rgb;
	t_rgb	rgb2;

	rgb = encodecolor(color);
	rgb2 = encodecolor(color2);
	rgb.r += rgb2.r;
	rgb.g += rgb2.g;
	rgb.b += rgb2.b;
	return (encode_rgb(rgb.r, rgb.g, rgb.b));
}

int	get_buddha_color(t_fract *f, int i, int j)
{
	int color;
	int color2;

	if (f->buddha[i][j][0] <= f->m1 / 5 && f->buddha[i][j][1] <= f->m2 / 5 && f->buddha[i][j][2] <= f->m3 / 5)
		return (0);
	if (f->m1 != 0) 
		color = f->color3[scale_int_to_int(f->buddha[i][j][0], get_ir(1, f->m1), get_ir(1, 9))];
	else
		color = 0;
	if (f->m2 != 0)
		color2 = f->color2[scale_int_to_int(f->buddha[i][j][1], get_ir(1, f->m2), get_ir(1, 9))];
	else
		color2 = 0;
	if (color2 != 0)
		color = add_rgb(color, color2);
	if (f->m3 != 0)
		color2 = f->color[scale_int_to_int(f->buddha[i][j][2], get_ir(1, f->m3), get_ir(1, 9))];
	else
		color2 = 0;
	if (color2 != 0)
	color = add_rgb(color, color2);
	return (color);
}

void	buddha_to_img(t_fract *fractol)
{
	int		i;
	int		j;
	t_pixel	p;

	fractol->m1 = get_buddha_max(fractol, 0);
	fractol->m2 = get_buddha_max(fractol, 1);
	fractol->m3 = get_buddha_max(fractol, 2);
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
		{
			p = apply_rotation(i, j, fractol);
			img_pixel_put(&fractol->img, p.y, p.x,
				get_buddha_color(fractol, i, j));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}

// int	diverges(t_fract *fractol, t_pixel p)
// {
// 	int			i;
// 	t_complex	c;
// 	t_complex	z;

// 	c.r = scale_int_to_double(p.x, get_ir(0, WIDTH),
// 			get_dr(-2, 1));
// 	c.i = scale_int_to_double(p.y, get_ir(0, HEIGHT),
// 			get_dr(-1.5, 1.5));
// 	z.r = 0;
// 	z.i = 0;
// 	i = -1;
// 	while (++i < MAX_IT)
// 	{
// 		z = complex_add(complex_sqr(z), c);
// 		if (z.r * z.r + z.i * z.i > 4)
// 			return (1);
// 	}
// 	return (0);
// }

int	diverges(t_fract *fractol, t_pixel p, int max_it)
{
	int			i;
	t_complex	c;
	t_complex	z;

	c.r = scale_int_to_double(p.x, get_ir(0, WIDTH),
			get_dr(fractol->x_min, fractol->x_max));
	c.i = scale_int_to_double(p.y, get_ir(0, HEIGHT),
			get_dr(fractol->y_min, fractol->y_max));
	z.r = 0;
	z.i = 0;
	i = -1;
	while (++i < max_it)
	{
		z = complex_add(complex_sqr(z), c);
		if (z.r * z.r + z.i * z.i > 4)
			return (1);
	}
	return (0);
}
