/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:14:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/09 13:40:25 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	escape_comparison(t_fractal *fractal)
{
	double	zx;
	double	zy;

	zx = (fractal->z_values->x * fractal->z_values->x);
	zy = (fractal->z_values->y * fractal->z_values->y);
	return ((zx + zy) > fractal->escape);
}

double	ft_scale(double nb, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * nb / o_max + n_min);
}

t_complex_num	complex_multi(t_complex_num a, t_complex_num b)
{
	t_complex_num	result;

	result.x = (a.x * b.x) - (a.y * b.y);
	result.y = (a.x * b.y) + (a.y * b.x);
	return (result);
}

t_complex_num	complex_pow(t_complex_num a, int b)
{
	t_complex_num	result;
	t_complex_num	base;
	int				exp;

	result.x = 1;
	result.y = 0;
	base = a;
	exp = b;
	if (exp < 0)
	{
		base = (t_complex_num){1.0 / base.x, -1.0 / base.y};
		exp = -exp;
	}
	while (exp > 0)
	{
		if (exp % 2 == 1)
			result = complex_multi(result, base);
		base = complex_multi(base, base);
		exp /= 2;
	}
	return (result);
}

t_complex_num	complex_sum(t_complex_num a, t_complex_num b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}
