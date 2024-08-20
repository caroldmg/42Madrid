/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:16:44 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/20 14:08:25 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	valid_fractol(char **argv)
{
	char const	*mandel = "mandelbrot";
	char const	*julia = "julia";

	if (!ft_strcmp(argv[1], mandel) || !ft_strcmp(argv[1], julia))
		return (true);
	else
		return (false);
}

void	ft_wrong_arg(void)
{
	ft_printf("los parámetros admitidos son: \n- madelbrot \n - julia \n");
	exit(EXIT_FAILURE);
}

