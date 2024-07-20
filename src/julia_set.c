/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:25 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 19:07:52 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
void	editjulia(t_fract *fractol, double x, double y)
{
	fractol->julia.r += x;
	fractol->julia.i += y;
	if (fractol->julia.r > 2)
		fractol->julia.r = -2;
	if (fractol->julia.i < 2)
		fractol->julia.i = -2;	
}
*/

int	iterations_julia(t_pixel p, t_fract *fractol)
{
	int			i;
	t_complex	z;

	z.r = scale_int_to_double(p.x, get_ir(0, WIDTH),
			get_dr(fractol->x_min, fractol->x_max));
	z.i = scale_int_to_double(p.y, get_ir(0, HEIGHT),
			get_dr(fractol->y_min, fractol->y_max));
	i = -1;
	while (++i < MAX_IT)
	{
		z = complex_add(complex_sqr(z), fractol->julia);
		if (z.r * z.r + z.i * z.i > 4)
			break ;
	}
	return (i);
}

void	render_julia(t_fract *fractol)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	while (HEIGHT > ++y)
	{
		x = -1;
		while (WIDTH > ++x)
		{
			i = iterations_julia(apply_rotation(x, y, fractol), fractol);
			img_pixel_put(&fractol->img, x, y, get_color_iter(i, fractol));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
