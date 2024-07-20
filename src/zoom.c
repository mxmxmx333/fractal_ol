/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:11:47 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 18:48:00 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom_in(t_fract *fractol, double zoom, int x, int y)
{
	double		new_range;
	t_d_ranges	pos;

	pos.min = scale_int_to_double(x, get_ir(0, WIDTH),
			get_dr(fractol->x_min, fractol->x_max));
	pos.max = scale_int_to_double(y, get_ir(0, HEIGHT),
			get_dr(fractol->y_min, fractol->y_max));
	new_range = (fractol->x_max - fractol->x_min) * (1.0 - zoom);
	new_range /= 2;
	fractol->x_min = pos.min - new_range;
	fractol->x_max = pos.min + new_range;
	fractol->y_max = pos.max + new_range;
	fractol->y_min = pos.max - new_range;
	fractol->render(fractol);
}

void	zoom_out(t_fract *fractol, double zoom, int x, int y)
{
	double		new_range;
	t_d_ranges	pos;

	pos.min = scale_int_to_double(x, get_ir(0, WIDTH),
			get_dr(fractol->x_min, fractol->x_max));
	pos.max = scale_int_to_double(y, get_ir(0, HEIGHT),
			get_dr(fractol->y_min, fractol->y_max));
	new_range = (fractol->x_max - fractol->x_min) * (1.0 + zoom);
	new_range /= 2;
	fractol->x_min = pos.min - new_range;
	fractol->x_max = pos.min + new_range;
	fractol->y_max = pos.max + new_range;
	fractol->y_min = pos.max - new_range;
	fractol->render(fractol);
}
