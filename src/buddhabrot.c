#include "fractal.h"

void	set_temp_to_zero(t_fract *fractol)
{
	int	i;
	int	j;

	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			fractol->temp[i][j] = 0;
	}
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

void	add_temp_to_buddha(t_fract *fractol)
{
	int	i;
	int	j;

	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
			fractol->buddha[i][j] += fractol->temp[i][j];
	}
}

void iterations_buddha(t_pixel p, t_fract *fractol)
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
		p.x = scale_double_to_int(z.r, fractol->x_min, fractol->x_max, 0, WIDTH - 1);
		p.y = scale_double_to_int(z.i, fractol->y_min, fractol->y_max, 0, HEIGHT - 1);
		if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
		{
			p = apply_rotation(p.x, p.y, fractol);
			fractol->temp[p.y][p.x]++;
		}
        if (z.r * z.r + z.i * z.i > 4)
		{
			add_temp_to_buddha(fractol);
			break ;
		}
    }
	set_temp_to_zero(fractol);
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

void	buddha_to_img(t_fract *fractol)
{
	int	i;
	int	j;
	int	max;

	max = get_buddha_max(fractol);
	i = -1;
	while (HEIGHT > ++i)
	{
		j = -1;
		while (WIDTH > ++j)
		{
			if (fractol->buddha[i][j] > max)
				img_pixel_put(&fractol->img, j, i, fractol->color[scale_int_to_int(fractol->buddha[i][j], 0, max, 0, 9)]);
		}
	}
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

void	render_buddhabrot(t_fract *fractol)
{
	int			x;
	int			y;
	t_pixel		p;

	color_img_black(fractol);
	set_buddha_to_zero(fractol);
	set_temp_to_zero(fractol);
	y = -1;
	while (HEIGHT > ++y)
	{
		x = -1;
		while (WIDTH > ++x)
		{
			p = apply_rotation(x, y, fractol);
			iterations_buddha(p, fractol);
		}
		printf("%d von %d\n",y, HEIGHT);
	}
	buddha_to_img(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img.img, 0, 0);
}