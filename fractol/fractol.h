/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/09/10 14:21:31 by cde-migu         ###   ########.fr       */
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
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red
# define SUPER_YELLOW	0xD69E02

typedef struct s_complex_num
{
	double	x; //real
	double	y; //imaginary
}	t_complex_num;

typedef struct s_fractal
{
	char			*name;
	void			*mlx;
	mlx_image_t		*image;
	int				window;
	t_complex_num	*z_values;
	t_complex_num	*c_values;

	// HOOKS AND EVENTS // TODO
	double			escape;
	int				max_iter;
	double			shift_x;
	double			shift_y;
	double			zoom;
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
void	fractal_init(t_fractal *fractal, char **argv);

//maths 
t_complex_num	*complex_mandel_formula(t_complex_num *z, t_complex_num *c);
t_complex_num	complex_sq(t_complex_num nb);
t_complex_num	complex_sum(t_complex_num z, t_complex_num c);
double			ft_scale(double unscaled, double new_min, double new_max, double old_max);
double	escape_comparison(t_fractal *fractal);

//IMAGE
// void	draw_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

// HOOKS

void	ft_scroll_zoom(double ydelta, double xdelta, void *param);
void	ft_keyhook(mlx_key_data_t keydata, t_fractal *fractal);

#endif