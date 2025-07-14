/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:13:36 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/14 17:38:35 by cde-migu         ###   ########.fr       */
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
	ft_putendl_fd("Algo ha fallado en la inicialización del programa.", 2);
}

int	check_return_life(int ret_code, t_all *all)
{
	if (ret_code == 1)
	{
		pthread_join(all->philo->philo_th, NULL);
		clean_everything(all);
		return (NO_ERROR);
	}
	else if (ret_code == 2)
		return (error_msg(UNKNOWN_ERROR));
	else
	{
		join_threads(all);
		clean_everything(all);
		return (NO_ERROR);
	}
}
