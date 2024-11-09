/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:34:21 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/09 13:45:39 by cde-migu         ###   ########.fr       */
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
	ft_printf("Available fractals: mandel, julia, phoenix \n");
	exit(EXIT_FAILURE);
}

void	ft_wrong_usage(void)
{
	ft_printf("Usage: ./fractol <fractal> \n \t Available fractals: mandel, julia, phoenix \n");
	ft_wrong_arg();
}

int	error_terminate_mlx(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_terminate(fractal->mlx);
	free(fractal);
	ft_error();
	return (EXIT_FAILURE);
}

void	ft_free_end(t_fractal *fractal)
{
	free(fractal->c_values);
	free(fractal->z_values);
	free(fractal->aux);
	mlx_terminate(fractal->mlx);
	free(fractal);
	exit(EXIT_SUCCESS);
}
