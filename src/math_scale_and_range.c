#include "fractal.h"

void	set_range(t_fract *fractol, double x_min, double x_max, double y_min, double y_max)
{
	fractol->x_min = x_min;
	fractol->x_max = x_max;
	fractol->y_min = y_min;
	fractol->y_max = y_max;
}

double  scale_int_to_double(int x, int old_min, int old_max, double new_min, double new_max)
{
    double  scale;

    scale = (double)(x - old_min) / (old_max - old_min);
    return (new_min + (scale * (new_max - new_min)));
}

int scale_int_to_int(int x, int old_min, int old_max, int new_min, int new_max)
{
    float	scale;
	int		res;

    scale = (float)(x - old_min) / (old_max - old_min);
	res = (new_min + (int)(scale * (new_max - new_min)));
    return (res);
}

int scale_double_to_int(double x, double old_min, double old_max, int new_min, int new_max)
{
	double  scale;

	scale = (x - old_min) / (old_max - old_min);
	return (new_min + (scale * (new_max - new_min)));
}

void	zoom_in(t_fract *fractol, double zoom, int x, int y)
{
	double 	new;
	double	pos_x;
	double	pos_y;
	double	new_range;

	pos_x = scale_int_to_double(x, 0, WIDTH, fractol->x_min, fractol->x_max);
	pos_y = scale_int_to_double(y, 0, HEIGHT, fractol->y_min, fractol->y_max);
	new_range = (fractol->x_max - fractol->x_min) * (1.0 - zoom);
	new_range /= 2;
	fractol->x_min = pos_x - new_range;
	fractol->x_max = pos_x + new_range;
	fractol->y_max = pos_y + new_range;
	fractol->y_min = pos_y - new_range;
	
	render_mandelbrot(fractol);
}

void	zoom_out(t_fract *fractol, double zoom, int x, int y)
{
	double 	new;
	double	pos_x;
	double	pos_y;
	double	new_range;

	pos_x = scale_int_to_double(x, 0, WIDTH, fractol->x_min, fractol->x_max);
	pos_y = scale_int_to_double(y, 0, HEIGHT, fractol->y_min, fractol->y_max);
	new_range = (fractol->x_max - fractol->x_min) * (1.0 + zoom);
	new_range /= 2;
	fractol->x_min = pos_x - new_range;
	fractol->x_max = pos_x + new_range;
	fractol->y_max = pos_y + new_range;
	fractol->y_min = pos_y - new_range;

	render_mandelbrot(fractol);
}
