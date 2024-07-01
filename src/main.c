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
	return (fractol);
}

int	handle_key(int keysym, t_fract *fractol)
{
	if (keysym == XK_Escape)
	{
		printf("The %d (ESC) key has been pressed\n", keysym);
		return (mlx_exit(fractol), 1);
	}
	printf("The %d key has been pressed\n\n", keysym);

	return (0);

}

int main(void)
{
	t_fract	*fractol;

	fractol = intialize();
	set_range(fractol, -2.0, 2.0);
	mlx_hook(fractol->win_ptr, 17, 0, mlx_exit, fractol);
	render_mandelbrot(fractol);
	mlx_key_hook(fractol->win_ptr, handle_key, fractol);
	put_colorset_oceanic_dreams(fractol);
	mlx_loop(fractol->mlx_ptr);
	return (mlx_exit(fractol), 0);

}