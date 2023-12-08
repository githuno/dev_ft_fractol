/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:30:03 by runoki            #+#    #+#             */
/*   Updated: 2023/12/08 18:02:17 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x, double y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		esc_value;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = x;
	c.y = y;
	esc_value = fractal->c_radius * fractal->c_radius;
	fractal->new.min = BLACK;
	fractal->new.max = fractal->high_color;
	fractal->old.min = fractal->iterations; //逆？
	fractal->old.max = 0; //逆？
	while (i < fractal->iterations)
	{
		z = add(sqr(z), c);
		if ((z.x * z.x) + (z.y * z.y) > esc_value)
			return (map(i, fractal->new, fractal->old));
		++i;
	}
	return (fractal->high_color);
}

int	julia(double x, double y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		esc_value;

	i = 0;
	z.x = x;
	z.y = y;
	c.x = fractal->mouse_x;
	c.y = fractal->mouse_y;
	esc_value = fractal->c_radius * fractal->c_radius;
	fractal->new.min = BLACK;
	fractal->new.max = fractal->high_color;
	fractal->old.min = fractal->iterations; //逆？
	fractal->old.max = 0; //逆？
	while (i < fractal->iterations)
	{
		z = add(sqr(z), c);
		if ((z.x * z.x) + (z.y * z.y) > esc_value)
			return (map(i, fractal->new, fractal->old));
		++i;
	}
	return (fractal->high_color);
}

int	mandelbar(double x, double y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		esc_value;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = x;
	c.y = y;
	esc_value = fractal->c_radius * fractal->c_radius;
	fractal->new.max = fractal->high_color;
	fractal->new.min = BLACK;
	fractal->old.max = fractal->iterations;
	fractal->old.min = 0;
	while (i < fractal->iterations)
	{
		z = add(cnj(sqr(z)), c);
		if ((z.x * z.x) + (z.y * z.y) > esc_value)
			return (map(i, fractal->new, fractal->old));
		++i;
	}
	return (fractal->high_color);
}
