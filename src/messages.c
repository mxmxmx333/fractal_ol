/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:15:16 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:53:54 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mlx_error(void)
{
	ft_putstr_fd(MLX_ERROR, 2);
	exit(1);
}

void	usage_error(void)
{
	ft_putstr_fd(USAGE, 2);
}

void	default_mode(void)
{
	ft_putstr_fd(USAGE, 1);
	ft_putstr_fd(DEFAULT_MODE, 1);
}
