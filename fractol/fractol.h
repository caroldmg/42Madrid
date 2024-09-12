/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/12 20:05:39 by cde-migu         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000

/*
 * COLORS
*/
# define BLACK       0x000000FF  // RGB(0, 0, 0)
# define WHITE       0xFFFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000FF  // RGB(255, 0, 0)
# define GREEN       0x00FF00FF  // RGB(0, 255, 0)
# define BLUE        0x0000FFFF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FFFF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00FF  // A blinding lime
# define NEON_ORANGE     0xFF6600FF  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066FF  // A deep purple
# define AQUA_DREAM      0x33CCCCFF  // A bright turquoise
# define HOT_PINK        0xE55982FF  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FFFF  // A radiant blue
# define LAVA_RED        0xFF3300FF // A bright, molten red
# define SUPER_YELLOW	0xFCBE11FF


typedef struct s_complex_num
{
	double	x;
	double	y;
}	t_complex_num;

typedef enum e_name
{
	mandel = 0,
	julia = 1,
	//other = 2, 
}	t_name;

typedef struct s_fractal
{
	t_name			name;
	void			*mlx;
	mlx_image_t		*image;
	int				window;
	t_complex_num	*z_values;
	t_complex_num	*c_values;
	t_complex_num	*c_original;
	int				color;

	// HOOKS AND EVENTS // TODO
	double			escape;
	int				max_iter;
	double			shift_x;
	double			shift_y;
	double			zoom;
}	t_fractal;

// error handle
void			ft_wrong_arg(void);
void			ft_error(void);

// init
void			fract_name(t_fractal *fractal, char *name, int argc);
void			fractal_init(t_fractal *fractal, char **argv);

//maths 
t_complex_num	*complex_mandel_formula(t_complex_num *z, t_complex_num *c);
double			ft_scale(double unscaled, double new_min, double new_max, double old_max);
double			escape_comparison(t_fractal *fractal);

//IMAGE
// void	draw_pixel(int x, int y, t_fractal *fractal);
void			fractal_render(t_fractal *fractal);
void	julia_random(t_fractal *fractal);

// HOOKS

void			ft_scroll_zoom(double ydelta, double xdelta, void *f);
void			ft_keyhook(mlx_key_data_t keydata, void *f);

#endif