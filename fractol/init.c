/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:12:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/01 12:35:35 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_init(t_fractal *fractal, char **argv)
{
	if (argv[2] && argv[3])
	{
		fractal->c_values->x = ft_atodbl(argv[2]);
		fractal->c_values->y = ft_atodbl(argv[3]);
	}
	else
	{
		fractal->c_values->x = -0.708188;
		fractal->c_values->y = 0.247709;
	}
	fractal->aux = malloc(sizeof(t_complex_num));
	if (!fractal->aux)
		return (error_terminate_mlx(fractal));
	fractal->aux->x = fractal->c_values->x;
	fractal->aux->y = fractal->c_values->y;
	return (0);
}

int	phoenix_init(t_fractal *fractal)
{
	fractal->c_values->x = 0.269;
	fractal->c_values->y = 0.00;
	fractal->aux = malloc(sizeof(t_complex_num));
	if (!fractal->aux)
		return (error_terminate_mlx(fractal->mlx));
	fractal->aux->x = 0.0;
	fractal->aux->y = -0.01;
	return (0);
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

int	data_init(t_fractal *fractal, char **argv)
{
	fractal->color_pos = 0;
	fractal->max_iter = 42;
	fractal->escape = 16;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color = SUPER_YELLOW;
	fractal->c_values = malloc(sizeof(t_complex_num));
	if (!fractal->c_values)
		return (error_terminate_mlx(fractal));
	fractal->z_values = malloc(sizeof(t_complex_num));
	if (!fractal->z_values)
		return (error_terminate_mlx(fractal->mlx));
	if (fractal->name == mandel)
		fractal->aux = NULL;
	else if (fractal->name == julia)
		return (julia_init(fractal, argv));
	else
		return (phoenix_init(fractal));
	return (0);
}

void	fractal_init(t_fractal *fractal, char **argv)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->mlx)
		ft_error();
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
		error_terminate_mlx(fractal);
	fractal->window = mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	if (fractal->window < 0)
		error_terminate_mlx(fractal);
	if (data_init(fractal, argv) == 1)
	{
		free(fractal);
		ft_error();
	}
}
