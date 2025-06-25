/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:54:08 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/25 13:17:55 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_all	*all;
	int		ret_code;

	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		return (error_msg(ERROR_MALLOC));
	if (check_valid_args(argc, argv) != NO_ERROR)
		return (error_msg(BAD_ARGS));
	all->philosophers = create_program(argv);
	if (!all->philosophers)
		return (error_msg(INIT_ERROR));
	all->monitor = init_monitor(all->philosophers);
	if (!all->monitor)
	{
		free(all->philosophers);
		return (error_msg(INIT_ERROR));
	}
	link_philo_monitor(all);
	ret_code = start_philo_life(all->philosophers);
	if (ret_code == 1)
	{
		pthread_join(all->philosophers->philo_th, NULL);
		clean_everything(all);
		return (NO_ERROR);
	}
	if (ret_code == 2)
		return (error_msg(UNKNOWN_ERROR));
	pthread_create(&all->monitor->philo_th, NULL, check_philo_death, all);
	pthread_join(all->monitor->philo_th, NULL);
	join_threads(all->philosophers, all->philosophers);
	clean_everything(all);
	return (0);
}
