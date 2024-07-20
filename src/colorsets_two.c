/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorsets_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:29:34 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 21:11:10 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// Ocean Breeze
void	put_colorset_ocean_breeze(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = DARK_BLUE;
	fractol->color[2] = MEDIUM_BLUE;
	fractol->color[3] = DODGER_BLUE;
	fractol->color[4] = DEEP_SKY_BLUE;
	fractol->color[5] = SKY_BLUE_X;
	fractol->color[6] = LIGHT_SKY_BLUE;
	fractol->color[7] = LIGHT_BLUE;
	fractol->color[8] = POWDER_BLUE;
	fractol->color[9] = PALE_TURQUOISE;
}

//Forest Canopy
void	put_colorset_forest_canopy(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = FOREST_GREEN_X;
	fractol->color[2] = SEA_GREEN;
	fractol->color[3] = MEDIUM_SEA_GREEN;
	fractol->color[4] = SPRING_GREEN;
	fractol->color[5] = MEDIUM_SPRING_GREEN;
	fractol->color[6] = LIGHT_GREEN;
	fractol->color[7] = PALE_GREEN;
	fractol->color[8] = YELLOW_GREEN;
	fractol->color[9] = LIME_GREEN;
}

//Autumn Blaze
void	put_colorset_autumn_blaze(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = BROWN;
	fractol->color[2] = FIREBRICK;
	fractol->color[3] = RED;
	fractol->color[4] = ORANGE_RED;
	fractol->color[5] = DARK_ORANGE;
	fractol->color[6] = ORANGE;
	fractol->color[7] = GOLD;
	fractol->color[8] = YELLOW;
	fractol->color[9] = LIGHT_YELLOW;
}

//Mystic Purple
void	put_colorset_mystic_purple(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = PURPLE;
	fractol->color[2] = DARK_MAGENTA;
	fractol->color[3] = BLUE_VIOLET;
	fractol->color[4] = VIOLET_X;
	fractol->color[5] = MEDIUM_ORCHID;
	fractol->color[6] = ORCHID;
	fractol->color[7] = PLUM;
	fractol->color[8] = THISTLE;
	fractol->color[9] = LAVENDER_X;
}

void	put_colorset_tropical_sunset(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = ORANGE;
	fractol->color[2] = LIGHT_CORAL;
	fractol->color[3] = INDIAN_RED;
	fractol->color[4] = DARK_SALMON;
	fractol->color[5] = SALMON;
	fractol->color[6] = LIGHT_SALMON;
	fractol->color[7] = PEACH_PUFF;
	fractol->color[8] = MOCCASIN;
	fractol->color[9] = PAPAYA_WHIP;
}
