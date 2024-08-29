/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/29 12:37:43 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
// {
//  fractal->x = 0;
//  fractal->y = 0;
//  while (fractal->x)
//  {
//   while (fractal->y)
//   {
//    if (ft_strcmp(query, "mandel") == 0)
//     calculate_mandelbrot(fractal);
//    else if (ft_strcmp(query, "julia") == 0)
//     calculate_julia(fractal, cx, cy);
//    else
//    {
//     ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
//     exit_fractal(fractal);
//    }
//    fractal->y++;
//   }
//   fractal->x++;
//   fractal->y = 0;
//  }
//  mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
//   0);
//  return (0);
// }

// RENDER

void	draw_pixel(int x, int y, t_fractal *fractal)
{
	int				i;
	int				color;
	t_complex_num	z;
	t_complex_num	c;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_scale(x, -2, +2, WIDTH);
	c.y = ft_scale(y, +2, -2, HEIGHT);
	// printf("dentro de drw_pixel, despues de ft_scale %i", x);
	while (i < fractal->max_iter)
	{	
		// z = z^2 + c 
		z = complex_mandel_formula(z, c);
	
		if (abs_complex_val(z) > 2) //escapa del set
		{
			color = ft_scale(i, 0, 255, fractal->max_iter);
			mlx_put_pixel(fractal->image, z.x, z.y, color);
			return ;
		}
		++i;
	}
	mlx_put_pixel(fractal->image, z.x, z.y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, fractal);
			// printf("dentro de fract render \t HEIGHT %i, \t WIDTH %i \n ---- HACE EL DRAW ----- \n", y, x);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(fractal->mlx, fractal->image, x, y) < 0)
		ft_error();
	
}