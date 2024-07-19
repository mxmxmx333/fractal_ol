#include "fractal.h"

static int get_color_iter(int i, t_fract *fractol)
{
    int index;

    if (i == MAX_IT)
        index = 9; // inside of the set
	else if (i == 0)
		index = 0; // outside of the circle
    else 
        index = scale_int_to_int(i, 1, MAX_IT, 1, 9); // outside of the set but not too far
	//printf("%d\n", index);
	return (fractol->color[index]);
}


t_pixel apply_rotation(int x, int y, t_fract *fractol)
{
	t_pixel rotated;

	if (fractol->rotation == 1)
		rotated = (t_pixel){y, WIDTH - 1 - x};
	else if (fractol->rotation == 2)
		rotated = (t_pixel){WIDTH - 1 - x, HEIGHT - 1 - y};
	else if (fractol->rotation == 3)
		rotated = (t_pixel){HEIGHT - 1 - y, x};
	else
		rotated = (t_pixel){x, y};
	return (rotated);
}

void render_mandelbrot(t_fract *fractol)
{
	int			x;
	int			y;
	int			i;

    y = -1;
    while (HEIGHT > ++y)
    {
        x = -1;
        while (WIDTH > ++x)
        {
			i = iterations_mb(apply_rotation(x, y, fractol), fractol);
            img_pixel_put(&fractol->img, x, y, get_color_iter(i, fractol));
        }
    }
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img.img, 0, 0);
}

int iterations_mb(t_pixel p, t_fract *fractol)
{
    int         i;
    t_complex   c;
    t_complex   z;
    double      temp;

    c.r = scale_int_to_double(p.x, 0, WIDTH, fractol->x_min, fractol->x_max);
    c.i = scale_int_to_double(p.y, 0, HEIGHT, fractol->y_min, fractol->y_max);
    z.r = 0;
    z.i = 0;
    i = -1;
    while (++i < MAX_IT)
    {
        z = complex_add(complex_sqr(z), c);
        if (z.r * z.r + z.i * z.i > 4)
            break ;
    }
    return (i);
}