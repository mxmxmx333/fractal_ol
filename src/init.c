/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:13:54 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 19:18:29 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_range(t_fract *fractol, t_d_ranges x, t_d_ranges y)
{
	fractol->x_min = x.min;
	fractol->x_max = x.max;
	fractol->y_min = y.min;
	fractol->y_max = y.max;
}

t_fract	*init_fractol(void)
{
	t_fract	*fractol;

	fractol = malloc(sizeof(t_fract));
	if (!fractol)
		return (exit(EXIT_FAILURE), NULL);
	fractol->mlx_ptr = NULL;
	fractol->win_ptr = NULL;
	fractol->img.img = NULL;
	fractol->img.addr = NULL;
	fractol->b_factor = 1;
	fractol->julia = (t_complex){-1, 0};
	return (fractol);
}

t_fract	*intialize(void)
{
	t_fract	*fractol;

	fractol = init_fractol();
	if (!fractol)
		return (exit(EXIT_FAILURE), NULL);
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		return (free(fractol), exit(EXIT_FAILURE), NULL);
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH,
			HEIGHT, "fract_ol");
	if (!fractol->win_ptr)
		return (mlx_exit(fractol), NULL);
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->img.img)
		return (mlx_exit(fractol), NULL);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	if (!fractol->img.addr)
		return (mlx_exit(fractol), NULL);
	fractol->rotation = 0;
	return (fractol);
}
