/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:45:32 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:27 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_colors(int keysym, t_fract *fractol)
{
	if (keysym == 49)
		put_colorset_autumn_harmony(fractol);
	if (keysym == 50)
		put_colorset_forest_whisper(fractol);
	if (keysym == 51)
		put_colorset_oceanic_dreams(fractol);
	if (keysym == 52)
		put_colorset_royal_elegance(fractol);
	if (keysym == 53)
		put_colorset_sunset_glow(fractol);
	if (keysym == 54)
		put_colorset_ocean_breeze(fractol);
	if (keysym == 55)
		put_colorset_forest_canopy(fractol);
	if (keysym == 56)
		put_colorset_autumn_blaze(fractol);
	if (keysym == 57)
		put_colorset_mystic_purple(fractol);
	if (keysym == 48)
		put_colorset_tropical_sunset(fractol);
	fractol->shader(fractol);
}

void	cpy_color_2(t_fract *fractol, int keysym)
{
	int		i;

	if (keysym == XK_w)
	{
		i = -1;
		while (++i < 10)
			fractol->color2[i] = fractol->color[i];
	}
}

void	cpy_color_3(t_fract *fractol)
{
	int	i;

	i = -1;
	while (++i < 10)
		fractol->color3[i] = fractol->color[i];
}
