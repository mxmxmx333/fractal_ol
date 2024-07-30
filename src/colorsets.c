/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorsets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:17:15 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 14:42:26 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

//ROYAL ELEGANCE
void	put_colorset_royal_elegance(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = WINE;
	fractol->color[2] = VIOLET;
	fractol->color[3] = AMETHYST;
	fractol->color[4] = ORCHID;
	fractol->color[5] = PLUM;
	fractol->color[6] = LAVENDER;
	fractol->color[7] = THISTLE;
	fractol->color[8] = MAUVE;
	fractol->color[9] = LILAC;
}

//OCEANIC DREAMS
void	put_colorset_oceanic_dreams(t_fract *fractol)
{
	fractol->color[0] = 0;
	fractol->color[1] = DEEP_BLUE;
	fractol->color[2] = TEAL;
	fractol->color[3] = SKY_BLUE;
	fractol->color[4] = TURQUOISE;
	fractol->color[5] = AQUAMARINE;
	fractol->color[6] = MINT_OCEANIC;
	fractol->color[7] = SEAFOAM;
	fractol->color[8] = LIGHT_AQUA;
	fractol->color[9] = CYAN;
}

//FOREST WHISPER
void	put_colorset_forest_whisper(t_fract *fractol)
{
	fractol->color[0] = FOREST_GREEN;
	fractol->color[1] = FERN;
	fractol->color[2] = OLIVE;
	fractol->color[3] = PINE;
	fractol->color[4] = JADE;
	fractol->color[5] = EMERALD;
	fractol->color[6] = MOSS;
	fractol->color[7] = SAGE;
	fractol->color[8] = LIME;
	fractol->color[9] = MINT_FOREST;
}

//SUNSET GLOW
void	put_colorset_sunset_glow(t_fract *fractol)
{
	fractol->color[0] = 0x0000;
	fractol->color[1] = BURNT_ORANGE;
	fractol->color[2] = TOMATO;
	fractol->color[3] = SALMON;
	fractol->color[4] = PEACH;
	fractol->color[5] = CORAL;
	fractol->color[6] = TANGERINE;
	fractol->color[7] = AMBER;
	fractol->color[8] = SUNSET_YELLOW;
	fractol->color[9] = GOLDENROD;
}

// Autumn Harmony
void	put_colorset_autumn_harmony(t_fract *fractol)
{
	fractol->color[0] = 0x0000000;
	fractol->color[1] = MAROON;
	fractol->color[2] = BURNT_ORANGE_AUTUMN;
	fractol->color[3] = RUST;
	fractol->color[4] = MAHOGANY;
	fractol->color[5] = COPPER;
	fractol->color[6] = OCHRE;
	fractol->color[7] = BRONZE;
	fractol->color[8] = PUMPKIN;
	fractol->color[9] = MUSTARD;
}
