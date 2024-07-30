/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_conditions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:28:30 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:54:00 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	condition_buddha(int argc, char **argv)
{
	return ((argc == 2 || argc == 5) && ft_strncmp
		(argv[1], "buddhabrot", 10) == 0 && argv[1][10] == '\0');
}
