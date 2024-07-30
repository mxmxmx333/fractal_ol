/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:22:53 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:44:45 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_render(t_fract *fractol, int keysym)
{
	if (keysym == XK_m)
	{
		fractol->render = render_mandelbrot;
		fractol->shader = shader_mandelbrot;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	if (keysym == XK_j)
	{
		fractol->render = render_julia;
		fractol->shader = shader_julia;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	if (keysym == XK_b)
	{
		fractol->render = render_buddhabrot;
		fractol->shader = buddha_to_img;
		fractol->rotation = 1;
		set_range(fractol, get_dr(-2.0, 1), get_dr(1.5, -1.5));
	}
	fractol->render(fractol);
}

void	render_mandelbrot(t_fract *fractol)
{
	int	x;
	int	y;
	int	i;

	fractol->m1 = MAX_IT;
	y = -1;
	while (HEIGHT > ++y)
	{
		x = -1;
		while (WIDTH > ++x)
		{
			i = iterations_mb(apply_rotation(x, y, fractol), fractol);
			fractol->buddha[y][x][0] = i;
		}
	}
	fractol->shader(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}

void	render_buddhabrot(t_fract *fractol)
{
	int		x;
	int		y;
	t_pixel	p;

	color_img_black(fractol);
	set_buddha_to_zero(fractol);
	y = -1;
	while (HEIGHT * fractol->b_factor > ++y)
	{
		x = -1;
		while (WIDTH * fractol->b_factor > ++x)
		{
			p = get_pixel(x, y);
			if (diverges(fractol, p, fractol->buddha_it1))
				iterations_buddha(p, fractol, fractol->buddha_it1, 0);
			if (diverges(fractol, p, fractol->buddha_it2))
				iterations_buddha(p, fractol, fractol->buddha_it2, 1);
			if (diverges(fractol, p, fractol->buddha_it3))
				iterations_buddha(p, fractol, fractol->buddha_it3, 2);
		}
	}
	buddha_to_img(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr,
		fractol->win_ptr, fractol->img.img, 0, 0);
}

void	render_julia(t_fract *fractol)
{
	int	x;
	int	y;
	int	i;

	fractol->m1 = 0;
	y = -1;
	while (HEIGHT > ++y)
	{
		x = -1;
		while (WIDTH > ++x)
		{
			i = iterations_julia(apply_rotation(x, y, fractol), fractol);
			if (i > fractol->m1)
				fractol->m1 = i;
			fractol->buddha[y][x][0] = i;
		}
	}
	fractol->shader(fractol);
}
