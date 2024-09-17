/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/17 15:45:05 by cde-migu         ###   ########.fr       */
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
	// barnsley_random();
}

/* static void	draw_barnsley(int x, int y, t_fractal *fractal)
{
	int				i;
	// double			rand;
	double			next_x;
	double			next_y;
	t_barns_trans	*values;

	i = 0;
	values =  malloc(sizeof(t_barns_trans));
	fractal->z_values->x = (ft_scale(x, -1, +1, WIDTH) * fractal->zoom);
	fractal->z_values->y = (ft_scale(y, +1, -1, HEIGHT) * fractal->zoom);

	// while (i < fractal->max_iter)
	// {
		// rand = barnsley_random();
		// if (rand < 0.01) 
		// 	values_transform_1(values);
		// else if (rand < 0.86)
			values_transform_2(values);
		// else if (rand < 0.93)
		// 	values_transform_3(values);
		// else
		// 	values_transform_4(values);
		// este if es el que nos permite calcular la transformacion de coordenadas segun probabilidad
		next_x = (values->a * fractal->z_values->x) + (values->b * fractal->z_values->y);
		next_y = (values->c * fractal->z_values->x) + (values->d * fractal->z_values->y) + values->e;
		i++;
		// mlx_put_pixel(fractal->image, next_x, next_y, fractal->color);
		mlx_put_pixel(fractal->image, x, y, fractal->color);
	// }
	fractal->z_values->x = next_x;
	fractal->z_values->y = next_y;
	// mlx_put_pixel(fractal->image, x, y, WHITE);
} */

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
