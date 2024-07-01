
#include "fractal.h"

void img_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int encode_rgb(byte r, byte g, byte b)
{
    return (r << 16 | g << 8 | b);
}

int get_color_iter(int i, t_fract *fractol)
{
    int index;

    if (i == MAX_IT)
        index = 0;
    else 
        index = scale_int_to_int(i, 1, MAX_IT, 1, 9);
	return (fractol->color[index]);
}