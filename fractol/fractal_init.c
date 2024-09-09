/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:12:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/09 18:47:39 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void	ft_keyhook(mlx_key_data_t keydata, t_fractal *fractal)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(fractal->mlx);
		mlx_terminate(fractal->mlx);
	}
	else if (keydata.key == MLX_KEY_LEFT)
		fractal->shift_x += 0.5;
	else if (keydata.key == MLX_KEY_RIGHT)
		fractal->shift_x -= 0.5;
	else if (keydata.key == MLX_KEY_UP)
		fractal->shift_y -= 0.5;
	else if (keydata.key == MLX_KEY_DOWN)
		fractal->shift_y += 0.5;
	else if (keydata.key == MLX_KEY_KP_ADD)
		fractal->max_iter += 10; 
	else if (keydata.key == MLX_KEY_KP_SUBTRACT)
		fractal->max_iter -= 10;
	fractal_render(fractal);
} */
static int	julia_init(t_fractal *fractal, char **argv)
{
	fractal->c_values->x = atodbl(argv[2]);
	fractal->c_values->y = atodbl(argv[3]);
}


static int	fract_data_init(t_fractal *fractal, char **argv)
{
	fractal->name = argv[1];
	fractal->max_iter = 142;
	fractal->escape = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->c_values = malloc(sizeof(t_complex_num));
	if (!fractal->c_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	if (ft_strcmp(fractal->name, "julia") == 0)
		julia_init(fractal, argv);
	fractal->z_values = malloc(sizeof(t_complex_num));
	if (!fractal->z_values)
	{
		mlx_terminate(fractal->mlx);
		return (1);
	}
	return (0);
}

void	fractal_init(t_fractal *fractal, char **argv)
{
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
	if (fract_data_init(fractal, argv))
	{
		free(fractal);
		ft_error();
	}
	// events_init() TODO
}

