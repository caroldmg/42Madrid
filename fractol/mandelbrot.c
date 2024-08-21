/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:41 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/20 17:01:29 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	get_index(int n, double c)
{
	if (n == 0)
		return (0);
	else
		return (get_index(n - 1, c) * get_index(n - 1, c) + c);
}

//This image has been generated by running the recursive formula up to twenty times per pixel

bool is_stable(double c, int max_iterations) {
    double z = 0.0;
    for (int i = 0; i < max_iterations; ++i) {
        z = pow(z, 2) + c;
        if (fabs(z) > 2.0) {
            return false;
        }
    }
    return true;
}

