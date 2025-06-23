/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:54:08 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 21:14:08 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	// int		ret_code;
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
	if (start_philo_life(philosophers) != 0)
		return (error_msg(1)); 
	pthread_create(&monitor->philo_th, NULL, check_philo_death, monitor);
	// printf("hola check_philo_death \n");
	pthread_join(monitor->philo_th, NULL);
	clean_everything(philosophers, monitor);
	return (0);
}
