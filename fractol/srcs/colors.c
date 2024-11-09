/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:42:16 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/09 13:41:54 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_init(unsigned int *colors)
{
	colors[0] = SUPER_YELLOW;
	colors[1] = NEON_ORANGE;
	colors[2] = PSYCHEDELIC_PURPLE;
	colors[3] = AQUA_DREAM;
	colors[4] = COOL_RED;
	colors[5] = CYAN_ELECTRIC;
	colors[6] = MCDONALDS;
	colors[7] = PNKY_PASTEL;
	colors[8] = CUTE_GREEN;
	colors[9] = LILLAC;
}

void	change_color(t_fractal *fractal)
{
	unsigned int	*colors;

	colors = malloc(10 * sizeof(unsigned int));
	color_init(colors);
	if (fractal->color_pos < 9)
		fractal->color_pos++;
	else
		fractal->color_pos = 0;
	fractal->color = colors[fractal->color_pos];
}
