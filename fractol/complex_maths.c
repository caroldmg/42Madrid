/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:14:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/12 12:36:05 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	escape_comparison(t_fractal *fractal)
{
	return ((fractal->z_values->x * fractal->z_values->x) + (fractal->z_values->y * fractal->z_values->y) > fractal->escape);
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
