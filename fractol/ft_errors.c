/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:34:21 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/27 17:15:04 by cde-migu         ###   ########.fr       */
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
	mlx_terminate(fractal->mlx);
	ft_error();
	return (EXIT_FAILURE);
}
