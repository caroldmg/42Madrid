/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/29 14:20:37 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// int	main (int argc, char **argv)
// {
// 	mlx_t	*ptr_mlx;

// 	if (argc == 1 || argv[1][0] == NULL || !valid_fractol(argv))
// 		return (EXIT_FAILURE);

// 	ptr_mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
// 	if (!ptr_mlx)
// 		ft_error();


// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	//mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(ptr_mlx);
// 	mlx_terminate(ptr_mlx);
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char **argv)
{
	t_fractal *fractal;

	fractal = NULL;
	//  if (parse(argc, argv) != 0)
	//  	return (1);
	if ((argc == 2 && (ft_strcmp(argv[1], "mandel") == 0) ) || (argc == 4 && (ft_strcmp(argv[1], "julia") == 0)))
	{
		fractal = malloc(sizeof(t_fractal));
		fractal_init(fractal);
		printf("ha terminado el fract init \n");
		
		fractal_render(fractal);
		mlx_loop(fractal->mlx);
		return (0);
	}
	else
	{
		ft_putendl_fd("Available fractals: mandel, julia", 1);
		ft_wrong_arg();
	}
}



