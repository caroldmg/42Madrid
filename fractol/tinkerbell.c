/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinkerbell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:30:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/17 18:16:46 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tinkerbell_init(t_fractal *fractal)
{
	fractal->max_iter = 10000;
	fractal->escape = 0;
	fractal->color = FERN;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->c_original = NULL;
	fractal->c_values = NULL;
	fractal->z_values = malloc(sizeof(t_complex_num));
	if (!fractal->z_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	fractal->z_values->x = 0.01;
	fractal->z_values->y = 0.01;
	return (0);
}

// 	fractal->escape = 0;
// 	fractal->color = FERN;
// 	fractal->shift_x = 0.0;
// 	fractal->shift_y = 0.0;
// 	fractal->zoom = 1.0;
// 	fractal->c_original = NULL;
// 	fractal->c_values = NULL;
// 	fractal->z_values = malloc(sizeof(t_complex_num));
// 	if (!fractal->z_values)
// 	{
// 		mlx_terminate(fractal->mlx);
// 		return (1);
// 	}
// 	return (0);

void	tinkerbell_values(t_tinker	*values)
{
	values->a = 0.9;
	values->b = -0.6013;
	values->c = 2.0;
	values->d = 0.5;
}

void	tinkerbell_ecuation(int x, int y, t_fractal *fractal)
{
	double 		next_x;
	double 		next_y;
	t_tinker	*values;

	values = malloc(sizeof(t_tinker));
	tinkerbell_values(values);
	fractal->z_values->x = (ft_scale(fractal->z_values->x, -1, +1, WIDTH) * fractal->zoom) + fractal->shift_x;
	fractal->z_values->y = (ft_scale(fractal->z_values->y, +1, -1, HEIGHT) * fractal->zoom) + fractal->shift_y;
	next_x = fractal->z_values->x *fractal->z_values->x - fractal->z_values->y * fractal->z_values->y + values->a * fractal->z_values->x + values->b * fractal->z_values->y;
	next_y = 2 * fractal->z_values->x * fractal->z_values->y + values->c * fractal->z_values->x + values->d * fractal->z_values->y;

	fractal->z_values->x = next_x;
	fractal->z_values->y = next_y;
	mlx_put_pixel(fractal->image, fractal->z_values->x, fractal->z_values->y, fractal->color);
	free(values);
}

void	tinker_render(t_fractal *fractal)
{
	int x;
	int y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			tinkerbell_ecuation(x, y, fractal);
			x++;	
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
}

