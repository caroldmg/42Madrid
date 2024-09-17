/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:04:48 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/17 18:38:20 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	values_transform_1(t_barns_trans values)
{
	values.a = 0.0;
	values.b = 0.0;
	values.c = -0.0;
	values.d = 0.16;
	values.e = 0.0;
}

void	values_transform_2(t_barns_trans values)
{
	values.a = 0.85;
	values.b = 0.04;
	values.c = -0.04;
	values.d = 0.85;
	values.e = 1.6;
}

void	values_transform_3(t_barns_trans values)
{
	values.a = 0.2;
	values.b = -0.26;
	values.c = 0.23;
	values.d = 0.22;
	values.e = 1.6;
}

void	values_transform_4(t_barns_trans values)
{
	values.a = -0.15;
	values.b = 0.28;
	values.c = -0.26;
	values.d = 0.24;
	values.e = 0.44;
}

// double	barnsley_random(void)
// {
// 	double	time;
	
// 	time = (mlx_get_time() * 100);
// 	time = time - (int)time;
// 	// printf("time random --> %f", time);

// 	return (time);
// }

void	fern_render(t_fractal *fractal)
{
	int				i;
	int				random;
	double			next_x;
	double			next_y;
	t_barns_trans	values;

	i = -1;
	while (i++ < fractal->max_iter)
	{
		//esta mal porque no se puede usar funcion prohibida
		random = rand() % 100;
		
		if (random <= 0) 
			values_transform_1(values);
		else if (random <= 6)
			values_transform_4(values);
		else if (random <= 15)
			values_transform_3(values);
		else
			values_transform_2(values);
		next_x = ((values.a * fractal->z_values->x) + (values.b * fractal->z_values->y)) * fractal->zoom;
		next_y = ((values.c * fractal->z_values->x) + (values.d * fractal->z_values->y) + values.e) * fractal->zoom;
		fractal->z_values->x = (next_x + 3) * 70;
		fractal->z_values->y = 800 - next_y * 70;
		mlx_put_pixel(fractal->image, next_x, next_y, fractal->color);
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	puts("hecho \n");
}
