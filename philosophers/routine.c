/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:55:33 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/24 19:40:15 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (is_dead(philo) == false)
	{
		pick_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (philo->id % 2 != 0)
			ft_usleep(10);
	}
	return (NULL);
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
		// if (pthread_detach(philo[i].philo_th) != NO_ERROR)
		// 	ret_code = 1;
		i++;
	}
	return (ret_code);
}

int	join_threads(t_philo *philo, t_philo *monitor)
{
	int	i;
	int	num;
	int	ret_code;

	i = 0;
	ret_code = 0;
	num  = monitor->num_philo;
	while (i < num)
	{
		if (pthread_join(philo[i].philo_th, NULL) != NO_ERROR)
			ret_code = 1;
		i++;
	}
	pthread_join(monitor->philo_th, NULL);
	return (ret_code);
}

bool	is_dead(t_philo *philo)
{
	return (philo->dead_flag);
}

void	kill_philos(t_philo *philosophers)
{
	int	i;
	int	nb;

	i = 0;
	nb = philosophers->num_philo;
	while (i < nb)
	{
		philosophers->dead_flag = true;
		i++;
	}
}
