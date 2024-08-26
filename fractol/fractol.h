/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/26 14:31:38 by cde-migu         ###   ########.fr       */
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

# define WIDTH 500
# define HEIGHT 500

typedef struct s_complex_num
{
	double	real;
	double	im;
}	t_complex_num;

bool	valid_fractol(char *name);
void	ft_wrong_arg(void);
void	ft_error(void);

#endif