/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:26:01 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 21:14:51 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	is_float(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && dot == 0)
				dot++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	usage_error(void)
{
	ft_putstr_fd(USAGE, 2);
}

void	default_mode(void)
{
	ft_putstr_fd(DEFAULT_MODE, 1);
}

t_complex	get_complex(double re, double im)
{
	t_complex	c;

	c.r = re;
	c.i = im;
	return (c);
}

int	input(int argc, char **argv, t_fract *fractol)
{
	if (argc == 1)
		return (default_mode(), 1);
	else if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argv[1][10] == '\0')
	{
		fractol->render = render_mandelbrot;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	else if (argc == 2 && ft_strncmp(argv[1], "buddhabrot", 10) == 0 && argv[1][10] == '\0')
	{
		fractol->render = render_buddhabrot;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0 && argv[1][5] == '\0')
	{
		if (!is_float(argv[2]) || !is_float(argv[3]))
			return (usage_error(), 0);
		fractol->julia = get_complex(ft_atof(argv[2]), ft_atof(argv[3]));
		fractol->render = render_julia;
		set_range(fractol, get_dr(-2.0, 2.0), get_dr(2.0, -2.0));
	}
	else
		return (usage_error(), 0);
	return (1);
}
