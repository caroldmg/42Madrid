/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/17 21:09:31 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal *fractal;

	fractal = NULL;
	if (argc == 2 || (argc == 4))
	{
		fractal = malloc(sizeof(t_fractal));
		if (!fractal)
			return (1);
		fract_name(fractal, argv[1], argc);
		fractal_init(fractal, argv);
		if (fractal->name == julia || fractal->name == mandel)
			fractal_jm_render(fractal);
		else
			phoenix_render(fractal);
		mlx_scroll_hook(fractal->mlx, ft_scroll_zoom, fractal);
		mlx_key_hook(fractal->mlx, &ft_keyhook, fractal);
		mlx_loop(fractal->mlx);
		return (0);
	}
	else
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_wrong_arg();
	}
}
