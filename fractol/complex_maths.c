/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:14:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/06 16:54:01 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double	abs_complex_val(t_complex_num *nb)
// {
// 	double result;

// 	result = 0;
// 	if (nb->x < 0)
// 		nb->x *= -1;
// 	result += nb->x;
// 	if (nb->y < 0)
// 		nb->y *= -1;
// 	result += nb->y;
// 	return (result);
// }

t_complex_num	complex_sq(t_complex_num nb)
{
	double	temp_x;

	temp_x = (nb.x * nb.x) - (nb.y * nb.y);
	nb.y = 2 * nb.x * nb.y;
	nb.x = temp_x;
	return (nb);
}

t_complex_num	complex_sum(t_complex_num z, t_complex_num c)
{
	t_complex_num	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;

	return (result);
}

double	escape_comparison(t_fractal *fractal)
{
	return ((fractal->z_values->x * fractal->z_values->x) + (fractal->z_values->y * fractal->z_values->y) > 4);
	//fractal->escape_value = 4
}

t_complex_num	*complex_mandel_formula(t_complex_num *z, t_complex_num *c)
{
	double	temp_x;

	temp_x = (z->x * z->x) - (z->y * z->y);
	z->y = 2 * z->x * z->y;
	z->x = temp_x;

	z->x += c->x;
	z->y += c->y;
	return (z);
}

double	ft_scale(double nb, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (nb - 0) / (o_max - 0) + n_min);
}
