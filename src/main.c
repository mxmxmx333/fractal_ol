/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:54:06 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 20:35:21 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fract	*fractol;

	fractol = intialize();
	set_render(fractol, 'm');
	if (!input(argc, argv, fractol))
		return (mlx_exit(fractol), 1);
	ft_putstr_fd(CONTROLS, 1);
	mlx_hook(fractol->win_ptr, 17, 0, mlx_exit, fractol);
	mlx_mouse_hook(fractol->win_ptr, handle_mouse, fractol);
	mlx_key_hook(fractol->win_ptr, handle_key, fractol);
	put_colorset_forest_whisper(fractol);
	fractol->render(fractol);
	mlx_loop(fractol->mlx_ptr);
	return (mlx_exit(fractol), 0);
}
