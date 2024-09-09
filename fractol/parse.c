/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:16:44 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/09 12:23:50 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_wrong_arg(void)
{
	ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
	exit(EXIT_FAILURE);
}

// int	parse(int argc, char **argv)
// {
// 	int	res;

// 	res = 0;
// 	if (argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0))
// 		make_mandelbrot();
// 	else if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0))
// 		make_julia();
// 	else
// 	{
// 		ft_putendl_fd("Available fractals: mandel, julia", 1);
// 		res = 1;
// 	}
// 	return (res);
// }

