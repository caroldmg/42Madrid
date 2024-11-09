/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/08 17:30:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_num	*complex_mandel_formula(t_complex_num *z, t_complex_num *c)
{
	*z = complex_sum(complex_pow(*z, 2), *c);
	return (z);
}

// t_complex_num	*complex_mandel_formula(t_complex_num *z, t_complex_num *c)
// {
// 	double	temp_x;

// 	temp_x = (z->x * z->x) - (z->y * z->y);
// 	z->y = 2 * z->x * z->y;
// 	z->x = temp_x;
// 	z->x += c->x;
// 	z->y += c->y;
// 	return (z);
// }

void	mandel_c(t_fractal *fractal)
{
	fractal->c_values->x = fractal->z_values->x;
	fractal->c_values->y = fractal->z_values->y;
}

void	draw_mandel_julia(int x, int y, t_fractal *fractal)
{
	int				i;
	int				color;

	i = 0;
	fractal->z_values->x = (ft_scale(x, -2, +2, fractal->w) * fractal->zoom) \
		+ fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +2, -2, fractal->h) * fractal->zoom) \
		+ fractal->shift_y;
	if (fractal->name == mandel)
		mandel_c(fractal);
	while (i < fractal->max_iter)
	{
		fractal->z_values = \
			complex_mandel_formula(fractal->z_values, fractal->c_values);
		if (escape_comparison(fractal))
		{
			color = fractal->color * i;
			mlx_put_pixel(fractal->image, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->image, x, y, BLACK);
}

void	fractal_jm_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractal->h)
	{
		x = 0;
		while (x < fractal->w)
		{
			draw_mandel_julia(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
}

void	julia_random(t_fractal *fractal)
{
	double	time_x;
	double	time_y;

	if (fractal->name == julia)
	{
		time_x = mlx_get_time() - (int) mlx_get_time() + fractal->aux->x;
		time_y = mlx_get_time() - (int) mlx_get_time() + fractal->aux->y;
		while (time_x > 1)
			time_x--;
		while (time_x < 0)
			time_x++;
		while (time_y > 1)
			time_y--;
		while (time_y < 0)
			time_y++;
		fractal->c_values->x = time_x * 2 - 1;
		fractal->c_values->y = time_y * 2 - 1;
	}
}
