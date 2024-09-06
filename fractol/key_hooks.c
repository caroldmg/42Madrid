/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:16:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/06 17:01:35 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
	(void)keydata;
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		ft_printf("Hola ");
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		ft_printf("cara");
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		ft_printf("cola!!");
}

void	hook(void *param, mlx_image_t img)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	// Create a new image
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (EXIT_FAILURE);

	ft_printf("%i",ft_atoi("89"));

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	
	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_key_hook(mlx, &ft_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
