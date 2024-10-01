/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:34:21 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/01 14:30:46 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_wrong_arg(void)
{
	ft_putendl_fd("Available fractals: mandel, julia, phoenix", 1);
	exit(EXIT_FAILURE);
}

int	error_terminate_mlx(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_terminate(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	ft_error();
	return (EXIT_FAILURE);
}

void	ft_close(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_close_window(fractal->mlx);
	mlx_terminate(fractal->mlx);
	// free(fractal->image);
	// free(fractal->mlx);
	free(fractal);
}
