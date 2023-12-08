/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:33 by runoki            #+#    #+#             */
/*   Updated: 2023/12/08 16:26:46 by runoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(int num, t_border new, t_border old)
{
	return ((new.max - new.min) * (num - old.min) / (old.max - old.min)
		+ new.min);
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
