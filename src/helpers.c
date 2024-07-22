/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:48:16 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 17:24:48 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_i_ranges	get_ir(int min, int max)
{
	t_i_ranges	r;

	r.min = min;
	r.max = max;
	return (r);
}

t_d_ranges	get_dr(double min, double max)
{
	t_d_ranges	r;

	r.min = min;
	r.max = max;
	return (r);
}

t_pixel	get_pixel(int x, int y)
{
	t_pixel	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	set_buddha_to_zero(t_fract *fractol)
{
	int	i;
	int	j;

	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			fractol->buddha[i][j][0] = 0;
	}
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			fractol->buddha[i][j][1] = 0;
	}
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			fractol->buddha[i][j][2] = 0;
	}
}

t_pixel	apply_rotation(int x, int y, t_fract *fractol)
{
	t_pixel	rotated;

	if (fractol->rotation == 1)
		rotated = (t_pixel){y, WIDTH - 1 - x};
	else if (fractol->rotation == 2)
		rotated = (t_pixel){WIDTH - 1 - x, HEIGHT - 1 - y};
	else if (fractol->rotation == 3)
		rotated = (t_pixel){HEIGHT - 1 - y, x};
	else
		rotated = (t_pixel){x, y};
	return (rotated);
}
