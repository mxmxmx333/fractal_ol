/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:30:17 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:37:31 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	buddha_color_condition(t_fract *f, int i, int j)
{
	int	c1;
	int	c2;
	int	c3;

	c1 = f->buddha[i][j][0];
	c2 = f->buddha[i][j][1];
	c3 = f->buddha[i][j][2];
	if (c1 <= f->m1 / 5 && c2 <= f->m2 / 5 && c3 <= f->m3 / 5)
		return (0);
	return (1);
}

static int	buddha_apply_color(int i, int num, t_fract *f)
{
	t_i_ranges	r;
	int			ci;

	r = get_ir(1, 9);
	ci = scale_int_to_int(i, get_ir(1, f->m1), r);
	if (num == 1)
		return (f->color3[ci]);
	ci = scale_int_to_int(i, get_ir(1, f->m2), r);
	if (num == 2)
		return (f->color2[ci]);
	ci = scale_int_to_int(i, get_ir(1, f->m3), r);
	if (num == 3)
		return (f->color[ci]);
	return (0);
}

int	get_buddha_color(t_fract *f, int i, int j)
{
	int	color;
	int	color2;

	if (buddha_color_condition(f, i, j) == 0)
		return (0);
	if (f->m1 != 0)
		color = buddha_apply_color(f->buddha[i][j][0], 1, f);
	else
		color = 0;
	if (f->m2 != 0)
		color2 = buddha_apply_color(f->buddha[i][j][1], 2, f);
	else
		color2 = 0;
	if (color2 != 0)
		color = add_rgb(color, color2);
	if (f->m3 != 0)
		color2 = buddha_apply_color(f->buddha[i][j][2], 3, f);
	else
		color2 = 0;
	if (color2 != 0)
		color = add_rgb(color, color2);
	return (color);
}
