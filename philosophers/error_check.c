/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:13:36 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/12 12:53:33 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(int value)
{
	if (value == BAD_ARGS)
		ft_putendl_fd(ARG_ER_MSG, 2);
	else if (value == ERROR_MALLOC)
		ft_putendl_fd("Malloc error :/", 2);
	return (value);
}

// TODO: funcion exit para liberar las estructuras
// TODO: funcion error que suelte el mensaje y que si me pasan la estructura me la libere
// TODO: funcion gettime
// TODO: funcion usleep