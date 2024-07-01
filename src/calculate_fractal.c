#include "fractal.h"

void render_mandelbrot(t_fract *fractol)
{
    int         x;
    int         y;
    int        i;
    y = -1;
    while (HEIGHT > ++y)
    {
        x = -1;
        while (WIDTH > ++x)
        {
            i = iterations_mb(x, y, fractol);
            img_pixel_put(&fractol->img, x, y, get_color_iter(i, fractol));
        }
    }
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img.img, 0, 0);
}

int iterations_mb(int x, int y, t_fract *fractol)
{
    int         i;
    t_complex   c;
    t_complex   z;
    double      temp;

    c.r = scale_int_to_double(x, 0, WIDTH, fractol->range_min, fractol->range_max);
    c.i = scale_int_to_double(y, 0, HEIGHT, -fractol->range_min, -fractol->range_max);
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