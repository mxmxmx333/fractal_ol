/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:13:54 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/23 11:33:12 by mbonengl         ###   ########.fr       */
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
// //Mystic Purple
// # define PURPLE          0x800080

// # define DARK_MAGENTA    0x8b008b
// # define BLUE_VIOLET     0x8a2be2
// # define VIOLET_X        0xee82ee
// # define MEDIUM_ORCHID   0xba55d3
// # define ORCHID          0xda70d6
// # define PLUM            0xdda0dd
// # define THISTLE         0xd8bfd8
// # define LAVENDER_X      0xe6e6fa

void	put_colorsets_1_2(t_fract *fractol)
{
	fractol->color2[0] = 0x000000;
	fractol->color2[1] = ORANGE;
	fractol->color2[2] = LIGHT_CORAL;
	fractol->color2[3] = INDIAN_RED;
	fractol->color2[4] = DARK_SALMON;
	fractol->color2[5] = SALMON;
	fractol->color2[6] = LIGHT_SALMON;
	fractol->color2[7] = PEACH_PUFF;
	fractol->color2[8] = MOCCASIN;
	fractol->color2[9] = PAPAYA_WHIP;
	fractol->color3[0] = 0x000000;
	fractol->color3[1] = PURPLE;
	fractol->color3[2] = DARK_MAGENTA;
	fractol->color3[3] = BLUE_VIOLET;
	fractol->color3[4] = VIOLET_X;
	fractol->color3[5] = MEDIUM_ORCHID;
	fractol->color3[6] = ORCHID;
	fractol->color3[7] = PLUM;
	fractol->color3[8] = THISTLE;
	fractol->color3[9] = LAVENDER_X;
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
	fractol->julia = (t_complex){-0.8, 0.4};
	fractol->buddha_it1 = 200;
	fractol->buddha_it2 = 500;
	fractol->buddha_it3 = 1000;
	put_colorsets_1_2(fractol);
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
