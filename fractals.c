
#include "fractol.h"
int		mandelbrot(double x, double y, t_fractol *fractal)
{
	t_complex z; //原点
	t_complex c; //座標平面上の点
	int i;
    double esc_value;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = x;
	c.y = y;
    esc_value = fractal->c_radius * fractal->c_radius;
	if((x * x) + (y * y) < 0.0001) //debug
		return BLACK; //debug
	
	while (i < fractal->iterations)
	{
		z = add(sqr(z), c); // z = z^2 + c
		// 原点からのベクトル距離をescape_valueと比較
		if ((z.x * z.x) + (z.y * z.y) > esc_value)
		{
			return map(i, BLACK, fractal->high_color, fractal->iterations, 0);
		}
		++i;
	}
	return fractal->high_color;
}

int     julia(double x, double y, t_fractol *fractal)
{
	t_complex z; // 原点
	t_complex c; // 定数
	int i;
    double esc_value;

	i = 0;
	z.x = x;
	z.y = y;
	c.x = fractal->mouse_x; // 定数の実部
	c.y = fractal->mouse_y; // 定数の虚部
    esc_value = fractal->c_radius * fractal->c_radius;
	while (i < fractal->iterations)
	{
		z = add(sqr(z), c); // z = z^2 + c
		// 原点からのベクトル距離を escape_value と比較
		if ((z.x * z.x) + (z.y * z.y) > esc_value)
		{
			return map(i, BLACK, fractal->high_color, 0, fractal->iterations);
		}
		++i;
	}
	return fractal->high_color;
}

int		mandelbar(double x, double y, t_fractol *fractal)
{
	t_complex z; //原点
	t_complex c; //座標平面上の点
	int i;
    double esc_value;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = x;
	c.y = y;
    esc_value = fractal->c_radius * fractal->c_radius;
	if((x * x) + (y * y) < 0.0001) //debug
		return BLACK; //debug
	
	while (i < fractal->iterations)
	{
        z = add(cnj(sqr(z)), c); // z = conj(z^2) + c
		if ((z.x * z.x) + (z.y * z.y) > esc_value)
		{
			return map(i, BLACK, fractal->high_color, 0, fractal->iterations);
		}
		++i;
	}
	return fractal->high_color;
}

int test_algo(double x, double y, t_fractol *fractal)
{
    double distance_squared = x * x + y * y;

	// 距離が1以下の条件
	if (distance_squared <= 1.0 * 1.0) {
		return WHITE;
	} else {
		return BLACK;
	}
}
