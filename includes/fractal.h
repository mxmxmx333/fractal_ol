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
# include <X11/Xlib.h>
# include <math.h>
# include "colors.h"

# ifndef WIDTH
#  define WIDTH 900 //with of the window
# endif

# ifndef HEIGHT
#  define HEIGHT 900 //height of the window
# endif

# ifndef MAX_IT
#  define MAX_IT 300 //maximum iteration
# endif

# ifndef ZOOM_FACTOR
#  define ZOOM_FACTOR 0.5 //zoom factor
# endif

# ifndef MOVE_FACTOR
#  define MOVE_FACTOR 0.1 //move factor
# endif

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

typedef struct s_pixel
{
	int	x; //x coordinate
	int	y; //y coordinate
}	t_pixel;

/*mlx data + fractal data*/
typedef struct s_fract
{
	void			*mlx_ptr; //mlx_init
	void			*win_ptr; //mlx_new_window
	char			rotation; //rotation
	t_img			img; //image struct
	double			x_min; //minimum x
	double			x_max; //maximum x
	double			y_min; //minimum y
	double			y_max; //maximum y
	void			(*render)(struct s_fract *fractol); //render function
	int				color[10]; //color palette
	int				buddha[HEIGHT][WIDTH]; //buddhabrot array
	int				temp[HEIGHT][WIDTH]; //temporary array
	int				condition; //condition für rendering
}	t_fract;

//coloring && rendering
void	img_pixel_put(t_img *img, int x, int y, int color);
int		encode_rgb(byte r, byte g, byte b);

//colorsets
void	put_colorset_royal_elegance(t_fract *fractol);
void	put_colorset_autumn_harmony(t_fract *fractol);
void	put_colorset_oceanic_dreams(t_fract *fractol);
void	put_colorset_forest_whisper(t_fract *fractol);
void	put_colorset_sunset_glow(t_fract *fractol);

//math && scaling
void		set_range(t_fract *fractol, double x_min, double x_max, double y_min, double y_max);
double		scale_int_to_double(int x, int old_min, int old_max, double new_min, double new_max);
int			scale_int_to_int(int x, int old_min, int old_max, int new_min, int new_max);
int 		scale_double_to_int(double x, double old_min, double old_max, int new_min, int new_max);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);
void		zoom_in(t_fract *fractol, double zoom, int x, int y);
void		zoom_out(t_fract *fractol, double zoom, int x, int y);
t_pixel 	apply_rotation(int x, int y, t_fract *fractol);


//fractals mandelbrot
void	render_mandelbrot(t_fract *fractol);
int		iterations_mb(t_pixel p, t_fract *fractol);
void	render_buddhabrot(t_fract *fractol);


//controls
void	set_render(t_fract *fractol, char c);
void	all_moves(int keysym, t_fract *fractol);
void	move(t_fract *fractol, double range, int x);
int		handle_mouse(int button, int x, int y, t_fract *fractol);



#endif