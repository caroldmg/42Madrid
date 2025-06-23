/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:54:08 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 22:02:33 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philosophers;
	t_philo	*monitor;

	if (check_valid_args(argc, argv) != NO_ERROR)
		return (error_msg(BAD_ARGS));
	philosophers = create_program(argv);
	if (!philosophers)
		return (error_msg(INIT_ERROR));
	monitor = init_monitor(philosophers);
	if (!monitor)
	{
		free(philosophers);
		return (error_msg(INIT_ERROR));
	}
	link_philo_monitor(philosophers, monitor);
	if (start_philo_life(philosophers) != 0)
		return (error_msg(UNKNOWN_ERROR));
	pthread_create(&monitor->philo_th, NULL, check_philo_death, monitor);
	pthread_join(monitor->philo_th, NULL);
	clean_everything(philosophers, monitor);
	return (0);
}
