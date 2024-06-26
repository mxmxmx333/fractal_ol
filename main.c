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
#include <mlx.h>


void	mlx_pixel_put(t_all *meta, int x, int y, int color)
{
	char	*dst;
	t_mlx_data	*data;

	data = meta->mlxd;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

int	destroy_all(t_all *meta)
{
	if (meta->mlxd->win_ptr)
		mlx_destroy_window(meta->mlxd->mlx_ptr, meta->mlxd->win_ptr);
	if (meta->mlxd->mlx_ptr)
	{
		mlx_destroy_display(meta->mlxd->mlx_ptr);
		free(meta->mlxd->mlx_ptr);
	}
	// if (meta->mlxd->mlx_ptr)
	// 	ft_free(meta->mlxd->mlx_ptr);
	if (meta->mlxd)
		ft_free(meta->mlxd);
	if (meta)
		ft_free(meta);
	return (exit(0), 0);
}

int	handle_key(int keysym, t_all *meta)
{
	if (keysym == XK_Escape)
	{
		destroy_all(meta);
		exit(0);
	}
	else 
		printf("Key: %x\n", keysym);
	return (0);
}

t_all	*meta_init(t_all *meta)
{
	meta = malloc(sizeof(t_all));
		if (!meta)
			return (NULL);
	meta->mlxd = malloc(sizeof(t_mlx_data));
	if (!meta->mlxd)
			return (free(meta), NULL);
	meta->mlxd->mlx_ptr = mlx_init();
	if (!meta->mlxd->mlx_ptr)
		return (free(meta->mlxd), free(meta), NULL);
	return (meta);
}

int	main(void)
{
	t_all	*meta;

	meta = NULL;
	meta = meta_init(meta);
	if (!meta)
		return (1);
	meta->mlxd->win_ptr = mlx_new_window(meta->mlxd->mlx_ptr, 800, 600, "Fract'ol");
	if (!meta->mlxd->win_ptr)
		return (destroy_all(meta), 2);
	mlx_key_hook(meta->mlxd->win_ptr, handle_key, meta);
	mlx_hook(meta->mlxd->win_ptr, 17, 0, destroy_all, meta);
	mlx_loop(meta->mlxd->mlx_ptr);
	destroy_all(meta);
	return (0);
}
