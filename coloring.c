
#include "fractal.h"

int encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}

void img_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
 
int color_screen(t_fract *fractol, int color)
{
    int x;
    int y;
    t_img img;

    img = fractol->img;
    y = -1;
    while (HEIGHT > ++y)
    {
        x = -1;
        while(WIDTH > ++x)
            img_pixel_put(&img, x, y, color);
    }
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, img.img, 0, 0);
}