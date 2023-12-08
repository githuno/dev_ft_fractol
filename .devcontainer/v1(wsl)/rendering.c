#include "fractol.h"
static	int	pixel_put(t_fractol *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img.addr
		 + (y * fractal->img.line_length
		  		+ x * (fractal->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

t_complex	scaled_point(int x, int y, t_fractol *fractal) //set_mouse_point()で使う
{
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = -(fractal->c_radius);
	x_max = +(fractal->c_radius);
	y_min = -(fractal->c_radius);
	y_max = +(fractal->c_radius);
    fractal->rendering.x = map(x, x_min * fractal->w_aspect,	x_max * fractal->w_aspect,
							 0, fractal->w_width);															 
    fractal->rendering.y = map(y, y_max, y_min,
							 0, fractal->w_height);
    if (fractal->w_aspect > 1.0)
    {
        fractal->rendering.x *= fractal->w_aspect;
        fractal->rendering.y *= fractal->w_aspect;
    }
	return (fractal->rendering);
}

void		rendering(t_fractol *fractal)
{
	int	x;
	int	y;

    y = -1;
	printf("		////rendering//////	shift(%lf, %lf)\n", fractal->shift_x, fractal->shift_y); //debug
	printf("		////rendering//////	mouse(%lf, %lf)\n", fractal->mouse_x, fractal->mouse_y); //debug
    while (++y < fractal->w_height)
    {
        x = -1;
        while (++x < fractal->w_width)
        {	
			fractal->rendering = scaled_point(x, y, fractal);
			fractal->rendering.x = (fractal->rendering.x / fractal->zoom) + fractal->shift_x;
			fractal->rendering.y = (fractal->rendering.y / fractal->zoom) + fractal->shift_y;
			fractal->rendering.color = fractal->algo(fractal->rendering.x, fractal->rendering.y, fractal);
			pixel_put(fractal, x, y, fractal->rendering.color);
        }
    }
    mlx_put_image_to_window(fractal->mlx,
		 fractal->win, fractal->img.ptr, 0, 0);
}
