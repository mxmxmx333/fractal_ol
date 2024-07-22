/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:15:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/22 22:56:19 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mlx_exit(t_fract *fractol)
{
	if (fractol->win_ptr)
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img);
	if (fractol->mlx_ptr)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
	}
	free(fractol);
	return (exit(EXIT_SUCCESS), 1);
}

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
	if (keysym == 93)
		fractol->shift += 1;
	if (fractol->render != render_buddhabrot)
		fractol->render(fractol);
	fractol->shader(fractol);
}

void	cpy_color_2(t_fract *fractol)
{
	int	i;

	i = -1;
	while (++i < 10)
		fractol->color2[i] = fractol->color[i];
}

void	cpy_color_3(t_fract *fractol)
{
	int	i;

	i = -1;
	while (++i < 10)
		fractol->color3[i] = fractol->color[i];
}

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
	if (keysym == XK_m)
		set_render(fractol, 'm');
	if (keysym == XK_j)
		set_render(fractol, 'j');
	if (keysym == XK_b)
		set_render(fractol, 'b');
	if (keysym == XK_r)
		fractol->rotation = (fractol->rotation + 1) % 4;
	if (keysym == XK_w)
		cpy_color_2(fractol);
	if (keysym == XK_q)
		cpy_color_3(fractol);
	if (keysym == XK_s)
		swap_shading(fractol);
	printf("keysym: %d\n", keysym);
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
