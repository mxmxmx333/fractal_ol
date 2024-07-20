/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:44:51 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/20 17:34:55 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	move_up(t_fract *fractol)
{
	if (fractol->rotation == 1)
	{
		fractol->x_min -= MOVE_FACTOR;
		fractol->x_max -= MOVE_FACTOR;
	}
	else if (fractol->rotation == 2)
	{
		fractol->y_min -= MOVE_FACTOR;
		fractol->y_max -= MOVE_FACTOR;
	}
	else if (fractol->rotation == 3)
	{
		fractol->x_min += MOVE_FACTOR;
		fractol->x_max += MOVE_FACTOR;
	}
	else
	{
		fractol->y_min += MOVE_FACTOR;
		fractol->y_max += MOVE_FACTOR;
	}
}

void	move_down(t_fract *fractol)
{
	if (fractol->rotation == 1)
	{
		fractol->x_min += MOVE_FACTOR;
		fractol->x_max += MOVE_FACTOR;
	}
	else if (fractol->rotation == 2)
	{
		fractol->y_min += MOVE_FACTOR;
		fractol->y_max += MOVE_FACTOR;
	}
	else if (fractol->rotation == 3)
	{
		fractol->x_min -= MOVE_FACTOR;
		fractol->x_max -= MOVE_FACTOR;
	}
	else
	{
		fractol->y_min -= MOVE_FACTOR;
		fractol->y_max -= MOVE_FACTOR;
	}
}

void	move_right(t_fract *fractol)
{
	if (fractol->rotation == 1)
	{
		fractol->y_min += MOVE_FACTOR;
		fractol->y_max += MOVE_FACTOR;
	}
	else if (fractol->rotation == 2)
	{
		fractol->x_min -= MOVE_FACTOR;
		fractol->x_max -= MOVE_FACTOR;
	}
	else if (fractol->rotation == 3)
	{
		fractol->y_min -= MOVE_FACTOR;
		fractol->y_max -= MOVE_FACTOR;
	}
	else
	{
		fractol->x_min += MOVE_FACTOR;
		fractol->x_max += MOVE_FACTOR;
	}
}

void	move_left(t_fract *fractol)
{
	if (fractol->rotation == 1)
	{
		fractol->y_min -= MOVE_FACTOR;
		fractol->y_max -= MOVE_FACTOR;
	}
	else if (fractol->rotation == 2)
	{
		fractol->x_min += MOVE_FACTOR;
		fractol->x_max += MOVE_FACTOR;
	}
	else if (fractol->rotation == 3)
	{
		fractol->y_min += MOVE_FACTOR;
		fractol->y_max += MOVE_FACTOR;
	}
	else
	{
		fractol->x_min -= MOVE_FACTOR;
		fractol->x_max -= MOVE_FACTOR;
	}
}

void	all_moves(int keysym, t_fract *fractol)
{
	if (keysym == XK_Up)
		move_up(fractol);
	if (keysym == XK_Down)
		move_down(fractol);
	if (keysym == XK_Left)
		move_left(fractol);
	if (keysym == XK_Right)
		move_right(fractol);
}
