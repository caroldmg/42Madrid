/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/22 11:48:30 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main (int argc, char **argv)
{
	mlx_t	*ptr_mlx;

	if (argc == 1 || argv[1][0] == NULL || !valid_fractol(argv))
		return (EXIT_FAILURE);

	ptr_mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!ptr_mlx)
		ft_error();


	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(ptr_mlx);
	mlx_terminate(ptr_mlx);
	return (EXIT_SUCCESS);
}


