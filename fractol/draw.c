/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/06 18:26:21 by cde-migu         ###   ########.fr       */
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

// static void	ft_put_pixel(int x, int y, int color, mlx_image_t *img)
// {
// 	int offset;
	
// 	offset = (y * img->width) + (x * (4/8));
// 	*(img->pixels + offset) = color;
// }

// RENDER

static void	draw_pixel(int x, int y, t_fractal *fractal)
{
	int				i;
	int				color;

	i = 0;
	fractal->z_values->x = 0.0;
	fractal->z_values->y = 0.0;
	fractal->c_values->x = ft_scale(x, -2, +2, WIDTH);
	fractal->c_values->y = ft_scale(y, +2, -2, HEIGHT);
	// printf("dentro de drw_pixel, despues de ft_scale %i", x);
	while (i < fractal->max_iter)
	{	
		// z = z^2 + c 
		fractal->z_values = complex_mandel_formula(fractal->z_values, fractal->c_values);
	
		// if (abs_complex_val(fractal->z_values) > 2) //escapa del set
		if (escape_comparison(fractal)) 
		{
			color = ft_scale(i, BLACK, WHITE, fractal->max_iter);
			// ft_put_pixel(x, y, color, fractal->image);
			mlx_put_pixel(fractal->image, x, y, color);
			return ;
		}
		++i;
	}
	// ft_put_pixel(x, y, BLACK, fractal->image);
	mlx_put_pixel(fractal->image, x, y, HOT_PINK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	y = 0;
	printf("ha entrado en fractal render");
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
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	
}
