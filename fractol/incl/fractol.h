/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/01 19:03:06 by cde-migu         ###   ########.fr       */
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

// Psychedelic colors
# define NEON_ORANGE     0xFF6600FF
# define PSYCHEDELIC_PURPLE 0x660066FF
# define AQUA_DREAM      0x33CCCCFF
# define HOT_PINK        0xE55982FF 
# define CYAN_ELECTRIC     0xFF2CFFFF
# define MCDONALDS		0xFFC72CFF
# define SUPER_YELLOW	0xFCBE11FF
# define PNKY_PASTEL	0xFFC4D6FF
# define CUTE_GREEN		0xC1E378FF

typedef enum e_name
{
	mandel = 0,
	julia = 1,
	phoenix = 2,
}	t_name;

typedef struct s_complex_num
{
	double	x;
	double	y;
}	t_complex_num;

typedef struct s_fractal
{
	t_name			name;
	void			*mlx;
	mlx_image_t		*image;
	int				window;
	t_complex_num	*z_values;
	t_complex_num	*c_values;
	t_complex_num	*aux;
	int				color;
	int				color_pos;

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
int				error_terminate_mlx(t_fractal *fractal);
void			ft_close(t_fractal *fractal);

// init
void			fractal_init(t_fractal *fractal, char **argv);

//maths 
double			ft_scale(double unscaled, double new_min, \
				double new_max, double old_max);
double			escape_comparison(t_fractal *fractal);
t_complex_num	complex_sum(t_complex_num a, t_complex_num b);
t_complex_num	complex_pow(t_complex_num a, int b);
t_complex_num	complex_multi(t_complex_num a, t_complex_num b);

//IMAGE
// void	draw_pixel(int x, int y, t_fractal *fractal);
void			fractal_jm_render(t_fractal *fractal);
void			julia_random(t_fractal *fractal);

//COLORS
void			change_color(t_fractal *fractal);

// PHOENIX
void			phoenix_render(t_fractal *fractal);
// void	draw_phoenix(int x, int y, t_fractal *fractal);

// HOOKS

void			ft_scroll_zoom(double ydelta, double xdelta, void *f);
void			ft_keyhook(mlx_key_data_t keydata, void *f);

#endif