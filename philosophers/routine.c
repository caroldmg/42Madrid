/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:55:33 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 21:14:20 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		pick_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

int	start_philo_life(t_philo *philo)
{
	int	i;
	int	num_philo;
	int	ret_code;

	i = 0;
	ret_code = 0;
	num_philo = philo->num_philo;
	while (i < num_philo)
	{
		philo[i].start_time = ft_get_time_ms();
		if (pthread_create(&philo[i].philo_th, NULL, philo_routine, &philo[i]) != NO_ERROR)
			ret_code = 1;
		if (pthread_detach(philo[i].philo_th) != NO_ERROR)
			ret_code = 1;
		i++;
	}
	return (ret_code);
}
