/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:14:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/17 20:55:41 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	escape_comparison(t_fractal *fractal)
{
	return ((fractal->z_values->x * fractal->z_values->x) + (fractal->z_values->y * fractal->z_values->y) > fractal->escape);
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

t_complex_num	multiply_complex(t_complex_num a, t_complex_num b)
{
    t_complex_num result;
    result.x = (a.x * b.x) - (a.y * b.y);
    result.y = (a.x * b.y) + (a.y * b.x);
    return (result);
}


t_complex_num	*phoenix_formula(t_complex_num *z, t_complex_num *c, t_complex_num *zlast)
{
	t_complex_num	*temp;
	// Z(n+1) = sqr(Z) + c(r) + c(i) * Z(n-1) //Zlast
	temp = complex_mandel_formula(z, c);
	*z = multiply_complex(*temp, *zlast);
	return (z);
}
