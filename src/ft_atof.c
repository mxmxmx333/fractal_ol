/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:36:15 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 20:35:15 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_atof(const char *str)
{
	double	result;
	double	dec;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	dec = 1;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str++ - '0';
		dec *= 10;
	}
	return (result * sign / dec);
}
