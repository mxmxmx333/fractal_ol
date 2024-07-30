/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:15:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 14:46:57 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	swap_shading(t_fract *fractol)
{
	if (fractol->shader == shader_julia)
		fractol->shader = shader_julia2;
	else if (fractol->shader == shader_julia2)
		fractol->shader = shader_julia4;
	else if (fractol->shader == shader_julia4)
		fractol->shader = shader_julia;
	else if (fractol->shader == shader_mandelbrot)
		fractol->shader = shader_mandelbrot2;
	else if (fractol->shader == shader_mandelbrot2)
		fractol->shader = shader_mandelbrot3;
	else if (fractol->shader == shader_mandelbrot3)
		fractol->shader = shader_mandelbrot4;
	else if (fractol->shader == shader_mandelbrot4)
		fractol->shader = shader_mandelbrot;
}

void	rotate(t_fract *fractol)
{
	fractol->rotation = (fractol->rotation + 1) % 4;
	if (fractol->render != render_buddhabrot)
		fractol->render(fractol);
}

int	handle_key(int keysym, t_fract *fractol)
{
	if (keysym == XK_Escape)
		return (mlx_exit(fractol), 1);
	if (keysym == 49 || keysym == 50 || keysym == 51 || keysym
		== 52 || keysym == 53 || keysym == 54 || keysym == 55
		|| keysym == 56 || keysym == 57 || keysym == 48 || keysym == 93)
		set_colors(keysym, fractol);
	if (keysym == XK_Up || keysym == XK_Down || keysym
		== XK_Left || keysym == XK_Right)
		all_moves(keysym, fractol);
	if (keysym == XK_m || keysym == XK_j || keysym == XK_b)
		set_render(fractol, keysym);
	if (keysym == XK_r)
		rotate(fractol);
	if (keysym == XK_w)
		cpy_color_2(fractol, keysym);
	if (keysym == XK_q)
		cpy_color_3(fractol);
	if (keysym == XK_s)
		swap_shading(fractol);
	fractol->shader(fractol);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fract *fractol)
{
	t_pixel	p;

	p = apply_rotation(x, y, fractol);
	if (button == 4 || button == 1)
		zoom_in(fractol, ZOOM_FACTOR, p.x, p.y);
	else if (button == 5 || button == 3)
		zoom_out(fractol, ZOOM_FACTOR, p.x, p.y);
	return (0);
}
/*
void	manipulations(int keysym, t_fract *fractol)
{
	if (keysym == XK_Page_Up)
		editjulia(fractol, 0.1, 0);
	if (keysym == XK_Page_Down)
		editjulia(fractol, 0, 0.1);
}
*/
