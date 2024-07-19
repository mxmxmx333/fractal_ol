
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

