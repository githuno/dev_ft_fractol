/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:46:47 by runoki            #+#    #+#             */
/*   Updated: 2023/12/11 18:50:37 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pixel_put(t_fractol *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img.addr + (y * fractal->img.line_length + x
			* (fractal->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

t_complex	scaling(int x, int y, t_fractol *fractal)
{
	t_complex	complex;

	fractal->c_new.min = -(fractal->c_radius) * fractal->w_aspect;
	fractal->c_new.max = +(fractal->c_radius) * fractal->w_aspect;
	fractal->c_old.min = 0;
	fractal->c_old.max = fractal->w_width;
	complex.x = map(x, fractal->c_new, fractal->c_old);
	fractal->c_new.min = -(fractal->c_radius);
	fractal->c_new.max = +(fractal->c_radius);
	fractal->c_old.min = 0;
	fractal->c_old.max = fractal->w_height;
	complex.y = map(y, fractal->c_new, fractal->c_old);
	if (fractal->w_aspect > 1.0)
	{
		complex.x *= fractal->w_aspect;
		complex.y *= fractal->w_aspect;
	}
	complex.x = (complex.x / fractal->zoom) + fractal->shift_x;
	complex.y = (complex.y / fractal->zoom) + fractal->shift_y;
	return (complex);
}

void	rendering(t_fractol *fractal)
{
	int		x;
	int		y;
	t_image	img;

	y = -1;
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
			fractal->complex = scaling(x, y, fractal);
			fractal->complex.color = fractal->algo(fractal->complex.x,
					fractal->complex.y, fractal);
			pixel_put(fractal, x, y, fractal->complex.color);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.ptr, 0, 0);
}
