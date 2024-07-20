/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_scale_and_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:33:57 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 17:34:37 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	scale_int_to_double(int x, t_i_ranges old, t_d_ranges new)
{
	double	scale;

	scale = (double)(x - old.min) / (old.max - old.min);
	return (new.min + (scale * (new.max - new.min)));
}

int	scale_int_to_int(int x, t_i_ranges old, t_i_ranges new)
{
	float	scale;
	int		res;

	scale = (float)(x - old.min) / (old.max - old.min);
	res = (new.min + (int)(scale * (new.max - new.min)));
	return (res);
}

int	scale_double_to_int(double x, t_d_ranges old, t_i_ranges new)
{
	double	scale;

	scale = (x - old.min) / (old.max - old.min);
	return (new.min + (int)(scale * (new.max - new.min)));
}
