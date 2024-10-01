/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:44:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/27 17:16:12 by cde-migu         ###   ########.fr       */
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

void	draw_phoenix(int x, int y, t_fractal *fractal)
{
	t_complex_num	z_last;
	t_complex_num	z_next;
	int				color;
	int				i;

	i = 0;
	fractal->z_values->x = (ft_scale(x, -2, +2, WIDTH) * fractal->zoom) \
							+ fractal->shift_x;
	fractal->z_values->y = (ft_scale(y, +2, -2, HEIGHT) * fractal->zoom) \
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
