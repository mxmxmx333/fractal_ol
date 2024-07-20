#include "fractal.h"

t_pixel	get_pixel(int x, int y)
{
	t_pixel	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	set_buddha_to_zero(t_fract *fractol)
{
	int	i;
	int	j;

	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			fractol->buddha[i][j] = 0;
	}
}

void iterations_buddha(t_pixel p, t_fract *fractol)
{
	int         i;
    t_complex   c;
    t_complex   z;

    c.r = scale_int_to_double(p.x, 0, WIDTH, fractol->x_min, fractol->x_max);
    c.i = scale_int_to_double(p.y, 0, HEIGHT, fractol->y_min, fractol->y_max);
    z.r = 0;
    z.i = 0;
    i = -1;
    while (++i < MAX_IT)
    {
        z = complex_add(complex_sqr(z), c);
		p.x = scale_double_to_int(z.r, fractol->x_min, fractol->x_max, 0, WIDTH - 1);
		p.y = scale_double_to_int(z.i, fractol->y_min, fractol->y_max, 0, HEIGHT - 1);
		if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
			fractol->buddha[p.y][p.x]++;
        if (z.r * z.r + z.i * z.i > 4)
			break ;
    }
}

int	get_buddha_max(t_fract *fractol)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			if (fractol->buddha[i][j] > max)
				max = fractol->buddha[i][j];
	}
	return (max);
}



void	color_img_black(t_fract *fractol)
{
	int	i;
	int	j;

	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			img_pixel_put(&fractol->img, j, i, 0x000000);
	}
}

void	buddha_to_img(t_fract *fractol)
{
	int	i;
	int	j;
	int	max;

	max = get_buddha_max(fractol);
	printf("max: %d\n", max);
	if (max == 0)
	{
		color_img_black(fractol);
		return ;
	}
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			img_pixel_put(&fractol->img, j, i, fractol->color[scale_int_to_int(fractol->buddha[i][j], 0, max, 0, 9)]);
	}
}

int	diverges(t_fract *fractol, t_pixel p)
{
	int         i;
	t_complex   c;
	t_complex   z;

	c.r = scale_int_to_double(p.x, 0, WIDTH, fractol->x_min, fractol->x_max);
	c.i = scale_int_to_double(p.y, 0, HEIGHT, fractol->y_min, fractol->y_max);
	z.r = 0;
	z.i = 0;
	i = -1;
	while (++i < MAX_IT)
	{
		z = complex_add(complex_sqr(z), c);
		if (z.r * z.r + z.i * z.i > 4)
			return (1);
	}
	return (0);
}

void	render_buddhabrot(t_fract *fractol)
{
	int			x;
	int			y;
	t_pixel		p;

	color_img_black(fractol);
	set_buddha_to_zero(fractol);
	y = -1;
	while (HEIGHT * fractol->b_factor > ++y)
	{
		x = -1;
		while (WIDTH * fractol->b_factor > ++x)
		{
			p = apply_rotation(x, y, fractol);
			if (diverges(fractol, p))
				iterations_buddha(p, fractol);
		}
		// printf("%d von %d\n",y, HEIGHT);
	}
	buddha_to_img(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img.img, 0, 0);
}