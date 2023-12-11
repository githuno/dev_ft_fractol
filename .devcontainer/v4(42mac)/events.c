/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:17:43 by runoki            #+#    #+#             */
/*   Updated: 2023/12/11 19:06:39 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_w(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	ctl_key(int keysym, t_fractol *fractal)
{
	if (keysym == 53 || keysym == 65307)
		close_w(fractal);
	else if (keysym == 123 || keysym == 65361)
		fractal->shift_x -= 0.1;
	else if (keysym == 126 || keysym == 65362)
		fractal->shift_y += 0.1;
	else if (keysym == 124 || keysym == 65363)
		fractal->shift_x += 0.1;
	else if (keysym == 125 || keysym == 65364)
		fractal->shift_y -= 0.1;
	else if (keysym == 24 || keysym == 59)
		fractal->iterations *= 1.1;
	else if (keysym == 27 || keysym == 45)
		fractal->iterations /= 1.1;
	else if (keysym == 18 || keysym == 49)
		set_params(fractal, "mandelbrot", WHITE, mandelbrot);
	else if (keysym == 19 || keysym == 50)
		set_params(fractal, "julia", NEON_ORANGE, julia);
	else if (keysym == 20 || keysym == 51)
		set_params(fractal, BONUS, LIME_SHOCK, mandelbar);
	else if (keysym == 6 || keysym == 114)
		set_params(fractal, fractal->name, AQUA_DREAM, fractal->algo);
	rendering(fractal);
	return (0);
}

static void	zoom(t_fractol *fractal, double scale)
{
	fractal->zoom *= scale;
	fractal->shift_x = (fractal->shift_x + (fractal->mouse_x * scale
				- fractal->mouse_x)) / scale;
	fractal->shift_y = (fractal->shift_y + (fractal->mouse_y * scale
				- fractal->mouse_y)) / scale;
}

int	ctl_mouse(int keysym, int x, int y, t_fractol *fractal)
{
	fractal->mouse_x = scaling(x, y, fractal).x;
	fractal->mouse_y = scaling(x, y, fractal).y;
	if (keysym == 4)
		zoom(fractal, 1.1);
	else if (keysym == 5)
		zoom(fractal, 1 / 1.1);
	else if (keysym == 1)
	{
		if (fractal->high_color == 0)
			fractal->high_color = 0xFFFFFF;
		else
			fractal->high_color /= (fractal->mouse_x / fractal->mouse_y);
	}
	rendering(fractal);
	return (0);
}

int	ctl_julia(int x, int y, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->mouse_x = scaling(x, y, fractal).x;
		fractal->mouse_y = scaling(x, y, fractal).y;
		rendering(fractal);
	}
	return (0);
}
