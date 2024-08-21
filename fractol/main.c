/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/20 14:16:28 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

// void	ft_error(void)
// {
// 	ft_printf("%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

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


typedef struct s_complex_num
{
	double	real;
	double	im;
}	t_complex_num;

#include <stdio.h>

int	main()
{
	t_complex_num z;
	t_complex_num c;
	double temp_real;

	z.real = 0;
	z.im = 0;

	c.real = 5;
	c.im = 2;

	for (int i = 0; i < 3; ++i)
	{
		// z = z^2 + c --> (a+b)2 = a^2 + b^2 + 2ab,
		// pero im^2 siempre es -1
		// x^2 - y^2 + 2xy
		temp_real = (z.real * z.real) - (z.im * z.im);
		z.im = 2 * z.real * z.im;
		z.real = temp_real;

		z.real += c.real;
		z.im += c.im;

		printf("iteration n -> %d \t real %f imaginary %f \n", i, z.real, z.im);
	}
}