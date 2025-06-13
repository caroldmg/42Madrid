/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:54:08 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/13 19:52:15 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo *philosophers;
	t_philo	*monitor;

	if (check_valid_args(argc, argv) != NO_ERROR)
		return (error_msg(BAD_ARGS));
	// aqui es donde inicializo la mesa de filosofos y cada uno de los filosofos
	philosophers = create_program(argv);
	// gestion de errores
	monitor = init_monitor(philosophers);
	// si no funciona, limpieza y mensaje de error
	link_philo_monitor(philosophers, monitor);
	
}