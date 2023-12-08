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

t_complex	scaling(int x, int y, t_fractol *fractal, int isShift) //set_mouse_point()で使う
{
	t_complex	complex;
	double x_min;
	double x_max;
	double y_min;
	double y_max;

	x_min = -(fractal->c_radius);
	x_max = +(fractal->c_radius);
	y_min = -(fractal->c_radius);
	y_max = +(fractal->c_radius);
    complex.x = map(x, x_min * fractal->w_aspect,	x_max * fractal->w_aspect,
							 0, fractal->w_width);
    complex.y = map(y, y_max, y_min,
							 0, fractal->w_height);
    if (fractal->w_aspect > 1.0)
    {
        complex.x *= fractal->w_aspect;
        complex.y *= fractal->w_aspect;
    }
	if(isShift == 1)
	{
		complex.x = (complex.x / fractal->zoom) + fractal->shift_x;
		complex.y = (complex.y / fractal->zoom) + fractal->shift_y;
		// complex.x = (complex.x + fractal->shift_x) / fractal->zoom;
		// complex.y = (complex.y + fractal->shift_y) / fractal->zoom;
	}
	return (complex);
}

void		rendering(t_fractol *fractal)
{
	int	x;
	int	y;

	y = -1;

	t_image		img;
	mlx_destroy_image(fractal->mlx, fractal->img.ptr);
	img.ptr = mlx_new_image(fractal->mlx, fractal->w_width, fractal->w_height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	fractal->img = img;

    while (++y < fractal->w_height)
    {
        x = -1;
        while (++x < fractal->w_width)
        {
			fractal->complex = scaling(x, y, fractal,1);
			// fractal->complex.x = (fractal->complex.x / fractal->zoom) + fractal->shift_x;
			// fractal->complex.y = (fractal->complex.y / fractal->zoom) + fractal->shift_y;
			fractal->complex.color = fractal->algo(fractal->complex.x, fractal->complex.y, fractal);

			if((fractal->complex.x * fractal->complex.x) + (fractal->complex.y * fractal->complex.y) < 0.0001){ //debug
				pixel_put(fractal, x, y, BLACK); //debug
			}else //debug
				pixel_put(fractal, x, y, fractal->complex.color);
        }
    }
    mlx_put_image_to_window(fractal->mlx,
		 fractal->win, fractal->img.ptr, 0, 0);
}
