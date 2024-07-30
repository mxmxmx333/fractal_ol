/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_and_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:39:05 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:17:48 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	encode_rgb(t_byte r, t_byte g, t_byte b)
{
	return (r << 16 | g << 8 | b);
}

int	mlx_exit(t_fract *fractol)
{
	if (fractol->win_ptr)
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
	if (fractol->mlx_ptr)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
	}
	free(fractol);
	return (exit(EXIT_SUCCESS), 1);
}

int	add_rgb(int color, int color2)
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
