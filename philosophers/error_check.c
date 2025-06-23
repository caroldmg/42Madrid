/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:13:36 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 22:02:44 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(int value)
{
	if (value == BAD_ARGS)
		ft_putendl_fd(ARG_ER_MSG, 2);
	else if (value == ERROR_MALLOC)
		ft_putendl_fd("Malloc error :/", 2);
	else if (value == UNKNOWN_ERROR)
		ft_putendl_fd("Unknown error :/", 2);
	else if (value == INIT_ERROR)
		error_monitor();
	return (value);
}

void	error_monitor(void)
{
	write(2, RED, ft_strlen(RED));
	ft_putendl_fd("Algo ha fallado en la inicialización del programa.", 2);
	write(2, RESET, ft_strlen(RESET));
}
