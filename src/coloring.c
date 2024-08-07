/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:15:59 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 14:41:36 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	apply_color(t_fract *fractol, int x, int y, int i)
{
	double	t;
	int		color;

	t = (double)i / MAX_IT;
	color = encode_rgb((9 * (1 - t) * t * t * t * 255),
			(15 * (1 - t) * (1 - t) * t * t * 255),
			(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255));
	img_pixel_put(&fractol->img, x, y, color);
}

int	get_color_iter_j(int i, t_fract *fractol)
{
	int	index;
	int	max_it;

	if (fractol->shader == shader_julia
		|| fractol->shader == shader_julia2 || fractol->shader == shader_julia4)
		max_it = fractol->m1;
	else
		max_it = MAX_IT;
	if (i == max_it)
		return (fractol->color[0]);
	else if (i == 0)
		return (fractol->color[0]);
	else
		index = i;
	return (fractol->color[index % 9 + 1]);
}

int	get_color_iter(int i, t_fract *fractol)
{
	int	index;
	int	max_it;

	if (fractol->shader == shader_julia
		|| fractol->shader == shader_julia2 || fractol->shader == shader_julia4)
		max_it = fractol->m1;
	else
		max_it = MAX_IT;
	if (i > max_it)
		index = 9;
	else if (i == 0)
		index = 0;
	else
		index = scale_int_to_int(i, get_ir(1, MAX_IT), get_ir(1, 9));
	return (fractol->color[index]);
}

void	color_img_black(t_fract *fractol)
{
	int	i;
	int	j;

	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			img_pixel_put(&fractol->img, j, i, 0x000000);
	}
}
