/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:33 by runoki            #+#    #+#             */
/*   Updated: 2023/12/11 18:59:17 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(int num, t_border c_new, t_border c_old)
{
	return ((c_new.max - c_new.min) * (num - c_old.min)
		/ (c_old.max - c_old.min) + c_new.min);
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

t_complex	cnj(t_complex a)
{
	t_complex	c;

	c.x = a.x;
	c.y = -a.y;
	return (c);
}
