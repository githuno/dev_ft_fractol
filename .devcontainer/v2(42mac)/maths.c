
#include "fractol.h"

double map(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = (a.x * a.x) - (a.y * a.y);
	c.y = 2 * a.x * a.y;
	return (c);
}

// 複素共役を計算する関数
t_complex	cnj(t_complex a)
{
	t_complex c;
	c.x = a.x;
	c.y = -a.y; // y 成分の符号を反転
	return (c);
}

// t_complex	mappoint(t_fractol *fractal, double x, double y)
// {
// 	t_complex	c;
// 	double		l;

// 	if (fractal->width < fractal->height)
// 		l = fractal->height * fractal->zoom;
// 	else
// 		l = fractal->width * fractal->zoom;
// 	x += fractal->xarrow ;
// 	y += fractal->yarrow ;
// 	c.x = 2 * fractal->radius * (x - fractal->width / 2) / l;
// 	c.y = 2 * fractal->radius * (y - fractal->height / 2) / l;
// 	return (c);
// }
