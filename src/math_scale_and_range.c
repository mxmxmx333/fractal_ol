#include "fractal.h"

void    set_range(t_fract *fractol, double min, double max)
{
    fractol->range_min = min;
    fractol->range_max = max;
}

double  scale_int_to_double(int x, int old_min, int old_max, double new_min, double new_max)
{
    double  scale;

    scale = (double)(x - old_min) / (old_max - old_min);
    return (new_min + (scale * (new_max - new_min)));
}

int scale_int_to_int(int x, int old_min, int old_max, int new_min, int new_max)
{
    int scale;

    scale = (x - old_min) / (old_max - old_min);
    return (new_min + (scale * (new_max - new_min)));
}

