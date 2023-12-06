/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:56:06 by runoki            #+#    #+#             */
/*   Updated: 2023/12/06 15:54:14 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	set_params(t_fractol *fractal, char *name, int color,
	int (*algo)(double, double,	t_fractol *))
{
	printf("ft_fractal 18: ok\n");
	if (fractal->name == NULL)
		fractal->name = name;
	else if(ft_strncmp(fractal->name, name, ft_strlen(name)) != 0)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.ptr);
		mlx_destroy_window(fractal->mlx, fractal->win);
		fractal->name = name;
		xdisplay_init(fractal);
	}
	fractal->algo = algo;
	fractal->iterations = 42;
	fractal->mouse_x = -0.4;
	fractal->mouse_y = 0.65;
	fractal->rendering.x = 0.0;
	fractal->rendering.y = 0.0;
	fractal->c_radius = RADIUS;
	fractal->w_width = WIDTH;
	fractal->w_height = HEIGHT;
	fractal->w_aspect = (double)WIDTH / (double)HEIGHT;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->high_color = color;
}

static void	valid_and_set_param(int argc, char **argv, t_fractol *fractal)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		set_params(fractal, argv[1], WHITE ,mandelbrot);
	else if (argc == 2 && ft_strncmp(argv[1], "julia", 5) == 0)
		set_params(fractal, argv[1], NEON_ORANGE, julia);
	else if (argc == 2 && ft_strncmp(argv[1], "mandelbar", 9) == 0)
		set_params(fractal, argv[1], MAGENTA_BURST, mandelbar);
	else
	{
		ft_printf(ARG_ERROR_MSG);
		exit(1);
	}
}

void	xdisplay_init(t_fractol *fractal)
{
	t_image		img;

	// ★★なるべく関数内で変数を宣言しないようにする★★
	// ★★なるべくアドレス渡しをする ◀ 見返す（&**） ★★
	// create window
	fractal->win = mlx_new_window(fractal->mlx, fractal->w_width
									, fractal->w_height, fractal->name);
	// create image
	img.ptr = mlx_new_image(fractal->mlx, fractal->w_width, fractal->w_height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	printf("img.line_length = %d\n", img.line_length);	
	// init fractal
	fractal->img = img;

	printf("fractal->img.addr = %p\n", fractal->img.addr); //debug
	printf("fractal->img.line_length = %d\n", fractal->img.line_length); //debug
	printf("fractal->img.bits_per_pixel = %d\n", fractal->img.bits_per_pixel); //debug
	printf("ft_fractal 82: ok\n"); //debug
	
	// hooks
	mlx_hook(fractal->win, KeyPress, KeyPressMask, ctl_key, fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, ctl_mouse,
		fractal);
	mlx_hook(fractal->win, MotionNotify, PointerMotionMask,	ctl_julia, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, close_w, fractal);
}

/* ************************************************************************** */
int	main(int argc, char **argv)
{
	t_fractol	fractal;

	makeLog(); //debug
	// init fractal
	fractal.name = NULL;
	// valid
	valid_and_set_param(argc, argv, &fractal);
	// mlx_init
	fractal.mlx = mlx_init();
	// xdisplay_init
	xdisplay_init(&fractal);
	// rendering
	rendering(&fractal);	
	// loop
	mlx_loop(fractal.mlx);
	return (0);
}
