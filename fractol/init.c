/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:12:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/13 18:33:11 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_init(t_fractal *fractal, char **argv)
{
	if (argv[2] && argv[3])
	{
		fractal->c_values->x = ft_atodbl(argv[2]);
		fractal->c_values->y = ft_atodbl(argv[3]);
	}
	else
	{
		fractal->c_values->x = 0.364052;
		fractal->c_values->y = -0.158;
	}
	fractal->c_original->x = fractal->c_values->x;
	fractal->c_original->y = fractal->c_values->y;
}

void	julia_random(t_fractal *fractal)
{
	double	time_x;
	double	time_y;

	time_x = mlx_get_time() - (int) mlx_get_time() + fractal->c_original->x;
	time_y = mlx_get_time() - (int) mlx_get_time() + fractal->c_original->y;
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
	rand();// entre 0 y MAX_INT
	//quiero entre 20 y 29
	//  20 + rand() % (29 - 20 + 1);
	//printf("    time --> %f \n", mlx_get_time());
	//printf("x --> %f \ny --> %f \n", fractal->c_values->x, fractal->c_values->y);
}

void	fract_name(t_fractal *fractal, char *name, int argc)
{
	if (argc == 2 && ft_strcmp(name, "mandel") == 0)
		fractal->name = mandel;
	else if (ft_strcmp(name, "julia") == 0)
		fractal->name = julia;
	else
		ft_wrong_arg();
}

static int	fract_jm_init(t_fractal *fractal, char **argv)
{
	fractal->max_iter = 42;
	fractal->escape = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color = SUPER_YELLOW;
	fractal->c_values = malloc(sizeof(t_complex_num));
	if (!fractal->c_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	fractal->c_original = malloc(sizeof(t_complex_num));
	if (!fractal->c_original)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
		
	if (fractal->name == julia)
		julia_init(fractal, argv);
	else
		fractal->c_original = NULL;
	fractal->z_values = malloc(sizeof(t_complex_num));
	if (!fractal->z_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	return (0);
}

static int	fract_barnsley_init(t_fractal *fractal)
{
	fractal->max_iter = 0;
	fractal->escape = 0;
	fractal->color = FERN;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->c_original = NULL;
	fractal->c_values = NULL;
	if (!fractal->z_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	return (0);
}

void	fractal_init(t_fractal *fractal, char **argv)
{
	int data_init;

	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->mlx)
		ft_error();
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
	if (fractal->name == barnsley)
		data_init = fract_barnsley_init(fractal);
	else
		data_init = fract_jm_init(fractal, argv);
	if (data_init == 1)
	{
		free(fractal);
		ft_error();
	}
}
