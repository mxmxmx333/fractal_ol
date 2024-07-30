/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:26:01 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:52:09 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	input_buddha(int argc, char **argv, t_fract *fractol)
{
	fractol->shader = buddha_to_img;
	if (argc == 2)
		return (1);
	else if (argc == 5 && is_pos_int(argv[2]) && is_pos_int \
			(argv[3]) && is_pos_int(argv[4]))
	{
		if (ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi \
			(argv[4]) < 1)
			return (0);
		fractol->buddha_it1 = ft_atoi(argv[2]);
		fractol->buddha_it2 = ft_atoi(argv[3]);
		fractol->buddha_it3 = ft_atoi(argv[4]);
		fractol->rotation = 1;
		return (1);
	}
	return (0);
}

int	input(int argc, char **argv, t_fract *fractol)
{
	if (argc == 1)
		return (default_mode(), 1);
	else if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractol->render = render_mandelbrot;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	else if (condition_buddha(argc, argv))
	{
		fractol->render = render_buddhabrot;
		set_range(fractol, get_dr(-2.0, 1), get_dr(1.5, -1.5));
		return (input_buddha(argc, argv, fractol));
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (!is_float(argv[2]) || !is_float(argv[3]))
			return (usage_error(), 0);
		fractol->julia = get_complex(ft_atof(argv[2]), ft_atof(argv[3]));
		fractol->shader = shader_julia;
		fractol->render = render_julia;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	else
		return (usage_error(), 0);
	return (1);
}
