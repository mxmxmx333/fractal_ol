/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:16:18 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 23:06:34 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	shader_julia(t_fract *fractol)
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
			apply_s_color(fractol, x, y, fractol->buddha[y][x][0]);
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}

void	shader_julia2(t_fract *fractol)
{
	int	x;
	int	y;
	int	i;
	int	color;

	y = -1;
	while (HEIGHT > ++y)
	{
		x = -1;
		while (WIDTH > ++x)
		{
			color = get_color_iter_j(fractol->buddha[y][x][0], fractol);
			img_pixel_put(&fractol->img, x, y, color);
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}


void	shader_julia4(t_fract *fractol)
{
	int		x;
	int		y;
	double	t;
	t_rgb	rgb;

	y = -1;
	while  (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			t = (double)fractol->buddha[y][x][0] / (double)fractol->m1;
			rgb.r = (t_byte)(9 * (1 - t) * pow(t, 3) * 255);
			rgb.g = (t_byte)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			rgb.b = (t_byte)(8.5 * pow((1 - t), 3) * t * 255);
			img_pixel_put(&fractol->img, x, y, encode_rgb(rgb.r, rgb.g, rgb.b));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
