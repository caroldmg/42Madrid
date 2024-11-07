/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:44:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/07 12:48:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_num	phoenix_formula(t_fractal *fractal, t_complex_num z_last)
{
	t_complex_num	res;

	res = complex_sum(complex_sum(\
					complex_multi(*fractal->z_values, *fractal->z_values), \
					*fractal->c_values), complex_multi(*fractal->aux, z_last));
	return (res);
}

void	phoenix_value(t_fractal *fractal, char **argv)
{
	if (ft_strcmp(argv[2], "2") == 0)
	{
		fractal->c_values->x = 0.5667;
		fractal->aux->x = -0.5;
	}
	if (ft_strcmp(argv[2], "3") == 0)
	{
		fractal->c_values->x = -0.4;
		fractal->c_values->y = 0.1;
		fractal->aux->x = 0.29550;
	}
	if (ft_strcmp(argv[2], "4") == 0)
	{
		fractal->c_values->x = 0.4;
		fractal->aux->x = -0.25;
	}
	if (ft_strcmp(argv[2], "5") == 0)
	{
		fractal->c_values->x = 0.1;
		fractal->c_values->y = 0.6;
		fractal->aux->x = -0.35;
	}
}

void	draw_phoenix(int x, int y, t_fractal *fractal)
{
	t_complex_num	z_last;
	t_complex_num	z_next;
	int				color;
	int				i;

	i = 0;
	fractal->z_values->x = (ft_scale(x, -2, +2, fractal->w) * fractal->zoom) \
							+ fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +2, -2, fractal->h) * fractal->zoom) \
							+ fractal->shift_y;
	z_last = (t_complex_num){0.0, 0.0};
	while (i < fractal->max_iter)
	{
		z_next = phoenix_formula(fractal, z_last);
		z_last = *fractal->z_values;
		*fractal->z_values = z_next;
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

void	phoenix_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractal->h)
	{
		x = 0;
		while (x < fractal->w)
		{
			draw_phoenix(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
}
