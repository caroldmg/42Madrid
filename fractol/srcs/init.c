/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:12:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/25 13:02:21 by cde-migu         ###   ########.fr       */
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

int	phoenix_init(t_fractal *fractal, char **argv)
{
	fractal->c_values->x = 0.269;
	fractal->c_values->y = 0.00;
	fractal->aux = malloc(sizeof(t_complex_num));
	if (!fractal->aux)
		return (error_terminate_mlx(fractal->mlx));
	fractal->aux->x = 0.0;
	fractal->aux->y = -0.01;
	if (argv[2])
		phoenix_value(fractal, argv);
	return (0);
}

int	data_init(t_fractal *fractal, char **argv)
{
	fractal->color_pos = 0;
	fractal->max_iter = 42;
	fractal->escape = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color = SUPER_YELLOW;
	fractal->h = HEIGHT;
	fractal->w = WIDTH;
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
		return (phoenix_init(fractal, argv));
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
		error_terminate_mlx(fractal);
}

void	fract_name(t_fractal *fractal, char *name, int argc)
{
	if (argc == 2 && ft_strcmp(name, "mandel") == 0)
		fractal->name = mandel;
	else if (ft_strcmp(name, "julia") == 0)
		fractal->name = julia;
	else if (ft_strcmp(name, "phoenix") == 0)
		fractal->name = phoenix;
	else
	{
		free(fractal);
		ft_wrong_arg();
	}
}
