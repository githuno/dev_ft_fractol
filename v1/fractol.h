/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:04:15 by runoki            #+#    #+#             */
/*   Updated: 2023/12/08 18:07:40 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# define ARG_ERROR_MSG \
	"Wrong args...This program requires only one argument, \n \
	\'julia\', \'mandelbrot\' or \'mandelbar\'\n"
# define BONUS "mandelbar"

// windows size
# define WIDTH 800
# define HEIGHT 800
// coordinate size
# define RADIUS 2.0

// COLORS
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

typedef struct s_image
{
	void		*ptr;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_complex
{
	double		x;
	double		y;
	int			color;
}				t_complex;

typedef struct s_border
{
	double		max;
	double		min;
}				t_border;

t_complex		sqr(t_complex a);
t_complex		add(t_complex a, t_complex b);
t_complex		cnj(t_complex a);
double			map(int num, t_border new, t_border old);

typedef struct s_fractol
{
	char		*name;
	int			(*algo)();
	void		*mlx;

	void		*win;
	double		w_width;
	double		w_height;
	double		w_aspect;

	t_image		img;
	t_complex	complex;
	t_border	new;
	t_border	old;
	double		c_radius;
	double		zoom;
	int			iterations;
	double		mouse_x;
	double		mouse_y;
	double		shift_x;
	double		shift_y;
	int			high_color;
}				t_fractol;

void			xdisplay_init(t_fractol *fractal);
void			set_params(t_fractol *fractal, char *name, int color,
					int (*algo)(double, double, t_fractol *));

t_complex		scaling(int x, int y, t_fractol *fractal);
void			rendering(t_fractol *fractal);

int				mandelbrot(double x, double y, t_fractol *fractal);
int				julia(double x, double y, t_fractol *fractal);
int				mandelbar(double x, double y, t_fractol *fractal);

int				close_w(t_fractol *fractal);
int				ctl_key(int keysym, t_fractol *fractal);
int				ctl_mouse(int keysym, int x, int y, t_fractol *fractal);
int				ctl_julia(int x, int y, t_fractol *fractal);

#endif
