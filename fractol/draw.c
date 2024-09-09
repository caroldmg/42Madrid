/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/09 18:53:06 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_pixel(int x, int y, t_fractal *fractal)
{
	int				i;
	int				color;

	i = 0;
	fractal->z_values->x = 0.0;
	fractal->z_values->y = 0.0;
	if (ft_strcmp(fractal->name, "mandel") == 0)
	{
		fractal->c_values->x = (ft_scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->c_values->y = (ft_scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	}
	// printf("dentro de drw_pixel, despues de ft_scale %i", x);
	while (i < fractal->max_iter)
	{	
		fractal->z_values = complex_mandel_formula(fractal->z_values, fractal->c_values);
	
		if (escape_comparison(fractal)) 
		{
			color = ft_scale(i, WHITE, BLACK, fractal->max_iter);
			mlx_put_pixel(fractal->image, x, y, color);
			return ;
		}
		++i;
	}
	mlx_put_pixel(fractal->image, x, y, HOT_PINK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	
}
