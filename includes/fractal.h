/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:54:15 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/26 17:28:00 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <math.h>
# include "colors.h"

# define WIDTH 1200 //with of the window
# define HEIGHT 1200 //height of the window
# define MAX_IT 42 //maximum iteration

typedef unsigned char	byte; //byte is an unsigned char used to store rgb values

/* image struct from mlx*/
typedef struct s_img
{
	void	*img; //mlx_new_image
	char	*addr; //mlx_get_data_addr
	int		bits_per_pixel; 
	int		line_length; 
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	r; //real part
	double	i; //imaginary part
}	t_complex;

/*mlx data + fractal data*/
typedef struct s_fract
{
	void		*mlx_ptr; //mlx_init
	void		*win_ptr; //mlx_new_window
	t_img		img; //image struct
	double		range_min; //minimum range
	double		range_max; //maximum range
	int			color[10]; //color palette
}	t_fract;

//coloring && rendering
void	img_pixel_put(t_img *img, int x, int y, int color);
int		get_color_iter(int i, t_fract *fractol);

//colorsets
void	put_colorset_royal_elegance(t_fract *fractol);
void	put_colorset_autumn_harmony(t_fract *fractol);
void	put_colorset_oceanic_dreams(t_fract *fractol);
void	put_colorset_forest_whisper(t_fract *fractol);
void	put_colorset_sunset_glow(t_fract *fractol);

//math && scaling
void		set_range(t_fract *fractol, double min, double max);
double		scale_int_to_double(int x, int old_min, int old_max, double new_min, double new_max);
int			scale_int_to_int(int x, int old_min, int old_max, int new_min, int new_max);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);

//fractals mandelbrot
void	render_mandelbrot(t_fract *fractol);
void    set_range(t_fract *fractol, double min, double max);
int		iterations_mb(int x, int y, t_fract *fractol);



#endif