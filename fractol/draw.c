/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/12 20:07:40 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandel_c(t_fractal *fractal)
{
	fractal->c_values->x = fractal->z_values->x;
	fractal->c_values->y = fractal->z_values->y;
}

static void	draw_pixel(int x, int y, t_fractal *fractal)
{
	int				i;
	int				color;

	i = 0;
	fractal->z_values->x = (ft_scale(x, -2 , +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +2 , -2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	if (fractal->name == mandel)
		mandel_c(fractal);

	while (i < fractal->max_iter)
	{	
		fractal->z_values = complex_mandel_formula(fractal->z_values, fractal->c_values);
		//  printf("x --> %f \ny --> %f \n", fractal->c_values->x, fractal->c_values->y);
	
		if (escape_comparison(fractal)) 
		{
			color = fractal->color * i;
			mlx_put_pixel(fractal->image, x, y, color);
			return ;
		}
		++i;
	}
	//printf("hola");
	mlx_put_pixel(fractal->image, x, y, BLACK);
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
