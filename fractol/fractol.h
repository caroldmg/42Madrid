/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/29 15:40:05 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0
# define WHITE 255

typedef struct s_complex_num
{
	double	x; //real
	double	y; //imaginary
}	t_complex_num;

typedef struct s_fractal
{
	void		*mlx;
	mlx_image_t	*image;
	int			window;
	int			max_iter;
	t_complex_num	*z_values;
	t_complex_num	*c_values;
}	t_fractal;

/*
	typedef struct mlx_image
{
	const uint32_t	width;int			
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;
*/



bool	valid_fractol(char *name);
void	ft_wrong_arg(void);
void	ft_error(void);
int		parse(int argc, char **argv);
void	fractal_init(t_fractal *fractal);

//maths 
t_complex_num	*complex_mandel_formula(t_complex_num *z, t_complex_num *c);
t_complex_num	complex_sq(t_complex_num nb);
t_complex_num	complex_sum(t_complex_num z, t_complex_num c);
double			ft_scale(double unscaled, double new_min, double new_max, double old_max);
double			abs_complex_val(t_complex_num *nb);

//IMAGE
void	draw_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

#endif