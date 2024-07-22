/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:22:53 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 11:20:19 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_render(t_fract *fractol, char c)
{
	if (c == 'm')
	{
		fractol->render = render_mandelbrot;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	if (c == 'j')
		fractol->render = render_julia;
	if (c == 'b')
	{
		fractol->render = render_buddhabrot;
		fractol->rotation = 1;
		set_range(fractol, get_dr(-2.0, 1), get_dr(1.5, -1.5));
	}
}

void	render_mandelbrot(t_fract *fractol)
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
			i = iterations_mb(apply_rotation(x, y, fractol), fractol);
			// img_pixel_put(&fractol->img, x, y, get_color_iter(i, fractol));
			apply_s_color(fractol, x, y, i);
		}
	}
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
			if (diverges(fractol, p))
				iterations_buddha(p, fractol);
		}
	}
	buddha_to_img(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr,
		fractol->win_ptr, fractol->img.img, 0, 0);
}
