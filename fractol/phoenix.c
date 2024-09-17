/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:44:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/17 21:08:55 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_phoenix(int x, int y, t_fractal *fractal)
{
	int	i;
	int	color;
	
	i = 0;
	fractal->z_values->x = (ft_scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->aux->x = fractal->z_values->x;
	fractal->aux->y = fractal->z_values->y;
	while (i < fractal->max_iter)
	{
		fractal->z_values = phoenix_formula(fractal->z_values, fractal->c_values, fractal->aux);
		if (escape_comparison(fractal)) 
		{
			color = fractal->color * i;
			mlx_put_pixel(fractal->image, x, y, color);
			return ;
		}
		++i;
	}
	mlx_put_pixel(fractal->image, x, y, BLACK);
}

void	phoenix_render(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_phoenix(x, y, fractal);
			x++;	
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
}
