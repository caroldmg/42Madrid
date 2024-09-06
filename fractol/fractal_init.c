/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:12:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/06 18:24:34 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fract_data_init(t_fractal *fractal)
{
	fractal->max_iter = 142;
	fractal->c_values = malloc(sizeof(t_complex_num));
	if (!fractal->c_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	fractal->z_values = malloc(sizeof(t_complex_num));
	if (!fractal->z_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	return (0);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->mlx)
		ft_error();
	printf("mlx funciona \n");
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		mlx_terminate(fractal->mlx);
		ft_error();
	}
	fractal->window = mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	if (fractal->window < 0)
	{
		mlx_terminate(fractal->mlx);
		ft_error();
	}
	if (fract_data_init(fractal))
	{
		free(fractal);
		ft_error();
	}
	// events_init() TODO
}

