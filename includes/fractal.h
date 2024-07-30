/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:54:15 by mbonengl          #+#    #+#             */
/*   Updated: 2024/07/30 15:49:24 by mbonengl         ###   ########.fr       */
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
# include "def_messages.h"
# include "libft.h"

# ifndef WIDTH
#  define WIDTH 900 //with of the window
# endif

# ifndef HEIGHT
#  define HEIGHT 900 //height of the window
# endif

# ifndef MAX_IT
#  define MAX_IT 930 //maximum iteration
# endif

# ifndef ZOOM_FACTOR
#  define ZOOM_FACTOR 0.5 //zoom factor
# endif

# ifndef MOVE_FACTOR
#  define MOVE_FACTOR 0.1 //move factor
# endif

//byte is an unsigned char used to store rgb values
typedef unsigned char	t_byte;

typedef struct s_rgb
{
	t_byte	r;
	t_byte	g;
	t_byte	b;
}	t_rgb;

typedef struct s_i_ranges
{
	int		min;
	int		max;
}	t_i_ranges;

typedef struct s_d_ranges
{
	double	min;
	double	max;
}	t_d_ranges;

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
	int				(*getcolor)(int i, struct s_fract *fractol);
	void			(*render)(struct s_fract *fractol);
	void			(*shader)(struct s_fract *fractol);
	int				m1; //max1
	int				m2; //max2
	int				m3; //max3
	int				color[10];
	int				color2[10];
	int				color3[10]; //color palette
	int				buddha[HEIGHT][WIDTH][3]; //buddhabrot array
	int				buddha_it1; //buddhabrot iteration 1
	int				buddha_it2; //buddhabrot iteration 2
	int				buddha_it3; //buddhabrot iteration 3
	int				b_factor; //factor for buddhabrot
	t_complex		julia; //julia set
}	t_fract;

//initialization & main
t_fract		*intialize(void);
int			input(int argc, char **argv, t_fract *fractol);
int			condition_buddha(int argc, char **argv);
int			is_float(char *str);
int			is_pos_int(char *str);

//messages
void		usage_error(void);
void		default_mode(void);
void		mlx_error(void);

//coloring && rendering
void		img_pixel_put(t_img *img, int x, int y, int color);
int			get_color_iter(int i, t_fract *fractol);
int			get_color_iter_j(int i, t_fract *fractol);
void		color_img_black(t_fract *fractol);
void		apply_color(t_fract *fractol, int x, int y, int i);
void		apply_s_color(t_fract *fractol, int x, int y, int i);
int			get_buddha_color(t_fract *f, int i, int j);

//RGB
t_rgb		encodecolor(int color);
int			encode_rgb(t_byte r, t_byte g, t_byte b);
int			add_rgb(int color, int color2);

//colorsets
void		put_colorset_royal_elegance(t_fract *fractol);
void		put_colorset_autumn_harmony(t_fract *fractol);
void		put_colorset_oceanic_dreams(t_fract *fractol);
void		put_colorset_forest_whisper(t_fract *fractol);
void		put_colorset_sunset_glow(t_fract *fractol);
void		put_colorset_ocean_breeze(t_fract *fractol);
void		put_colorset_forest_canopy(t_fract *fractol);
void		put_colorset_autumn_blaze(t_fract *fractol);
void		put_colorset_mystic_purple(t_fract *fractol);
void		put_colorset_tropical_sunset(t_fract *fractol);

//img to window
void		buddha_to_img(t_fract *fractol);
void		shader_mandelbrot(t_fract *fractol);
void		shader_mandelbrot2(t_fract *fractol);
void		shader_mandelbrot3(t_fract *fractol);
void		shader_mandelbrot4(t_fract *fractol);

void		shader_julia(t_fract *fractol);
void		shader_julia2(t_fract *fractol);
void		shader_julia4(t_fract *fractol);

//math && scaling
void		set_range(t_fract *fractol, t_d_ranges x, t_d_ranges y);
double		scale_int_to_double(int x, t_i_ranges old, t_d_ranges new);
int			scale_int_to_int(int x, t_i_ranges old, t_i_ranges new);
int			scale_double_to_int(double x, t_d_ranges old, t_i_ranges new);
void		zoom_in(t_fract *fractol, double zoom, int x, int y);
void		zoom_out(t_fract *fractol, double zoom, int x, int y);

//math && scaling custom
t_pixel		apply_rotation(int x, int y, t_fract *fractol);
t_pixel		get_pixel(int x, int y);

//complex math
t_complex	get_complex(double re, double im);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);

//renderers
void		render_mandelbrot(t_fract *fractol);
void		render_julia(t_fract *fractol);
void		render_buddhabrot(t_fract *fractol);

//iterations
int			iterations_mb(t_pixel p, t_fract *fractol);
int			iterations_julia(t_pixel p, t_fract *fractol);
void		iterations_buddha(t_pixel p, t_fract *fractol, int max_it, int pos);
int			diverges(t_fract *fractol, t_pixel p, int max_it);

//controls
void		set_render(t_fract *fractol, int keysym);
void		all_moves(int keysym, t_fract *fractol);
void		move_up(t_fract *fractol);
void		move_down(t_fract *fractol);
void		move_right(t_fract *fractol);
void		move_left(t_fract *fractol);
int			handle_mouse(int button, int x, int y, t_fract *fractol);
int			mlx_exit(t_fract *fractol);
int			handle_key(int keysym, t_fract *fractol);
void		manipulations(int keysym, t_fract *fractol);
void		editjulia(t_fract *fractol, double x, double y);
void		set_colors(int keysym, t_fract *fractol);
void		cpy_color_2(t_fract *fractol, int keysym);
void		cpy_color_3(t_fract *fractol);

//helpers
t_i_ranges	get_ir(int min, int max);
t_d_ranges	get_dr(double min, double max);
void		set_buddha_to_zero(t_fract *fractol);
double		ft_atof(const char *str);

#endif