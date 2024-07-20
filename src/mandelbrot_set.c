/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:27:47 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 18:35:57 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	iterations_mb(t_pixel p, t_fract *fractol)
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
	while (++i < MAX_IT)
	{
		z = complex_add(complex_sqr(z), c);
		if (z.r * z.r + z.i * z.i > 4)
			break ;
	}
	return (i);
}
