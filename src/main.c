/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:54:06 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/26 17:29:16 by mbonengl         ###   ########.fr       */
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
	// if (fractol->img.addr)
	// 	free(fractol->img.addr);
	free(fractol);
	return (exit(EXIT_SUCCESS), 1);
}

t_fract *init_fractol(void)
{
	t_fract *fractol;

	fractol = malloc(sizeof(t_fract));
	if (!fractol)
		return (exit(EXIT_FAILURE), NULL);
	fractol->mlx_ptr = NULL;
	fractol->win_ptr = NULL;
	fractol->img.img = NULL;
	fractol->img.addr = NULL;
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
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, "fract_ol");
	if (!fractol->win_ptr)
		return (mlx_exit(fractol), NULL);
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->img.img)
		return (mlx_exit(fractol), NULL);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, &fractol->img.line_length, &fractol->img.endian);
	if (!fractol->img.addr)
		return (mlx_exit(fractol), NULL);
	fractol->rotation = 0;
	return (fractol);
}

void	move(t_fract *fractol, double range, int x)
{
	if (x == 1)
	{
		fractol->y_max -= range * MOVE_FACTOR;
		fractol->y_min -= range * MOVE_FACTOR;
	}
	if (x == 2)
	{
		fractol->x_max -= range * MOVE_FACTOR;
		fractol->x_min -= range * MOVE_FACTOR;
	}
	if (x == 3)
	{
		fractol->y_max += range * MOVE_FACTOR;
		fractol->y_min += range * MOVE_FACTOR;
	}
	if (x == 4)
	{
		fractol->x_max += range * MOVE_FACTOR;
		fractol->x_min += range * MOVE_FACTOR;
	}
}

void	all_moves(int keysym, t_fract *fractol)
{
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym == XK_Right)
		move(fractol, fractol->x_max - fractol->x_min, 1);
	if (keysym == XK_Down)
		move(fractol, fractol->x_max - fractol->x_min, 3);
	if (keysym == XK_Left)
		move(fractol, fractol->y_max - fractol->y_min, 2);
	if (keysym == XK_Right)
		move(fractol, fractol->y_max - fractol->y_min, 4);
}
int	handle_key(int keysym, t_fract *fractol)
{
	if (keysym == XK_Escape)
		return (mlx_exit(fractol), 1);
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
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym == XK_Right)
		all_moves(keysym, fractol);
	if (keysym == XK_m)
		set_render(fractol, 'm');
	// if (keysym == XK_j)
	// 	set_render(fractol, 'j');
	if (keysym == XK_b)
		set_render(fractol, 'b');
	if (keysym == XK_r)
		fractol->rotation = (fractol->rotation + 1) % 4;
	printf("%d\n", keysym);
	fractol->render(fractol);

	return (0);
}

int	handle_mouse(int button, int x, int y, t_fract *fractol)
{
	if (button == 4 || button == 1) 
	{
		printf("The %d (scroll up) button has been pressed at x=%d, y=%d\n", button, x, y);
		zoom_in(fractol, ZOOM_FACTOR, x, y);
	} 
	else if (button == 5 || button == 3) {
		printf("The %d (scroll down) button has been pressed at x=%d, y=%d\n", button, x, y);
		zoom_out(fractol, ZOOM_FACTOR, x, y);
	}
	printf("mouse wurde benutzt\n");
	return (0);
}

void	set_render(t_fract *fractol, char c)
{
	if (c == 'm')
	{
		fractol->render = render_mandelbrot;
		set_range(fractol, -2.0, 2.0, 2.0, -2.0);
	}
	// if (c == 'j')
	// 	fractol->render = render_julia;
	if (c == 'b')
		fractol->render = render_buddhabrot;
} 

int main(void)
{
	t_fract	*fractol;

	fractol = intialize();
	set_render(fractol, 'm');
	mlx_hook(fractol->win_ptr, 17, 0, mlx_exit, fractol);
	mlx_mouse_hook(fractol->win_ptr, handle_mouse, fractol);
	mlx_key_hook(fractol->win_ptr, handle_key, fractol);
	put_colorset_forest_whisper(fractol);
	render_mandelbrot(fractol);

	mlx_loop(fractol->mlx_ptr);
	return (mlx_exit(fractol), 0);

}