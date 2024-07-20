/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:33:13 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 17:33:35 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return (c);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.r = a.r * a.r - a.i * a.i;
	c.i = 2 * a.r * a.i;
	return (c);
}
