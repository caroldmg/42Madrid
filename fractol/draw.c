/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/13 18:28:30 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandel_c(t_fractal *fractal)
{
	fractal->c_values->x = fractal->z_values->x;
	fractal->c_values->y = fractal->z_values->y;
}

static void	draw_mandel_julia(int x, int y, t_fractal *fractal)
{
	int				i;
	int				color;

	i = 0;
	fractal->z_values->x = (ft_scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (fractal->name == mandel)
		mandel_c(fractal);
	while (i < fractal->max_iter)
	{	
		fractal->z_values = complex_mandel_formula(fractal->z_values, fractal->c_values);	
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

static void	draw_barnsley(int x, int y, t_fractal *fractal)
{
	int				i;
	double			rand;
	double			next_x;
	double			next_y;
	t_barns_trans	*values;

	fractal->z_values->x = (ft_scale(x, -1, +1, WIDTH) * fractal->zoom) + fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +1, -1, HEIGHT) * fractal->zoom) + fractal->shift_y;
	while (i < fractal->max_iter)
	{
	// rand = random_num
	// valor "aleatorio" para dibujar un punto u otro, segun el tiempo que lleva abierta, 
	// pero para que sea más aleatorio cogeré la centésima
		
		if (rand < 0.01) 
			values_transform_1(values);
		else if (rand < 0.86)
			values_transform_2(values);
		else if (rand < 0.93)
			values_transform_3(values);
		else
			values_transform_4(values);
		// este if es el que nos permite calcular la transformacion de coordenadas segun probabilidad
		next_x = (values->a * x) + (values->b * y);
		next_y = (values->c * x) + (values->d * y) + values->e;
		i++;
	}
	fractal->z_values->x = next_x;
	fractal->z_values->y = next_y;
	mlx_put_pixel(fractal->image, x, y, fractal->color);
}

void	fractal_jm_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_mandel_julia(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);	
}

void	fractal_b_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_barnsley(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);	
}