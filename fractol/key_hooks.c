/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:16:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/20 16:27:04 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		ft_printf("Hola ");
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		ft_printf("cara");
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		ft_printf("cola!!");
}

int	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &ft_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
