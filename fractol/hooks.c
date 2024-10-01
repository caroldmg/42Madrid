/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:16:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/01 13:04:24 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keyhook(mlx_key_data_t keydata, void *f)
{
	t_fractal	*fractal;

	fractal = f;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_close(fractal);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		fractal->max_iter += 10;
	else if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		fractal->max_iter -= 10;
	else if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		julia_random(fractal);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		change_color(fractal);
	if (fractal->name == phoenix)
		phoenix_render(fractal);
	else
		fractal_jm_render(fractal);
}

void	ft_scroll_zoom(double ydelta, double xdelta, void *f)
{
	t_fractal	*fractal;

	(void)ydelta;
	fractal = f;
	if (xdelta > 0)
	{
		fractal->zoom *= 0.95;
	}
	else if (xdelta < 0)
	{
		fractal->zoom *= 1.05;
	}
	if (fractal->name == phoenix)
		phoenix_render(fractal);
	else
		fractal_jm_render(fractal);
}
