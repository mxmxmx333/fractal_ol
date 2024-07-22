/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soph_coloring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:57:30 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 22:40:50 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_rgb	encodecolor(int color)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

int	interpolate(int color1, int color2, double t)
{
	t_rgb	rgb1;
	t_rgb	rgb2;
	t_rgb	rgb;

	rgb1 = encodecolor(color1);
	rgb2 = encodecolor(color2);
	rgb.r = (1 - t) * rgb1.r + t * rgb2.r;
	rgb.g = (1 - t) * rgb1.g + t * rgb2.g;
	rgb.b = (1 - t) * rgb1.b + t * rgb2.b;
	return (encode_rgb(rgb.r, rgb.g, rgb.b));
}

int	soph_blending(t_fract *fractol, int i)
{
	float	t;
	int		index;
	int		max_it;

	if (fractol->shader == shader_julia
		|| fractol->shader == shader_julia2 || fractol->shader == shader_julia4)
		max_it = fractol->m1;
	else
		max_it = MAX_IT;
	if (i == max_it || i == 0)
		return (0);
	t = (double)i / max_it;
	index = scale_int_to_int(i, get_ir(0, max_it), get_ir(1, 9));
	return (interpolate(fractol->color[index], fractol->color[index + 1], t));
}

void	apply_s_color(t_fract *fractol, int x, int y, int i)
{
	int	color;

	color = soph_blending(fractol, i);
	img_pixel_put(&fractol->img, x, y, color);
}

// int	soph_mod_blending(t_fract *fractol, int i)
// {
// 	float	t;
// 	int 	index;

// 	if (i == MAX_IT || i == 0)
// 		return (0);
// 	t = (double)i / MAX_IT;
// 	index = scale_int_to_int(i, get_ir(0, MAX_IT), get_ir(1, 9));
// 	if (t % 1 == 0)
// 		return (fractol->color[index]);
// 	return (interpolate(fractol->color[index], fractol->color[index + 1], t));
// }

// void	apply_s_mod_color(t_fract *fractol, int x, int y, int i)
// {
// 	int	color;

// 	color = soph_mod_blending(fractol, i);
// 	img_pixel_put(&fractol->img, x, y, color);
// }