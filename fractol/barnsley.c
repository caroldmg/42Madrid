/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:04:48 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/13 18:37:52 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	values_transform_1(t_barns_trans *values)
{
	values->a = 0.0;
	values->b = 0.0;
	values->c = -0.0;
	values->d = 0.16;
	values->e = 0.0;
}

static void	values_transform_4(t_barns_trans *values)
{
	values->a = 0.85;
	values->b = 0.04;
	values->c = -0.04;
	values->d = 0.85;
	values->e = 1.6;
}

static void	values_transform_3(t_barns_trans *values)
{
	values->a = 0.2;
	values->b = -0.26;
	values->c = 0.23;
	values->d = 0.22;
	values->e = 1.6;
}

static void	values_transform_4(t_barns_trans *values)
{
	values->a = -0.15;
	values->b = 0.28;
	values->c = -0.26;
	values->d = 0.24;
	values->e = 0.44;
}

double	random_num(void)
{
	double	time;
	
	time = mlx_get_time();

	return (time);
}

