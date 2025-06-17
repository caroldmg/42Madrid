/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:42:28 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/17 20:33:36 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_monitor(t_philo *philo)
{
	t_philo	*monitor;
	
	monitor = ft_calloc(1, sizeof(t_philo));
	if (!monitor)
		return (ERROR_MALLOC);
	monitor->id = 0;
	monitor->nb_meals_to_eat = philo->nb_meals_to_eat;
	monitor->time_to_die = philo->time_to_die;
	monitor->time_to_eat = philo->time_to_die;
	monitor->time_to_sleep = philo->time_to_sleep;
	monitor->meals_eaten = philo->meals_eaten;
	monitor->num_forks = philo->num_philo;
	monitor->num_philo = philo->num_philo;
	monitor->fork_mutex = NULL;
	monitor->lock = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor->lock, NULL);
	return (monitor);
}

void	link_philo_monitor(t_philo *philo, t_philo *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->num_philo)
	{
		philo[i].lock = monitor->lock;
		i++;
	}
	monitor->start_time = ft_get_time_ms();
}

void	start_threads(t_philo *philo)
{
	int	i;
	int	num_philo;

	i = 0;
	num_philo = philo->num_philo;
	while (i < num_philo)
	{
		philo[i].start_time = ft_get_time_ms();
		pthread_create(&philo[i], NULL, philo_routine, &philo[i]);
		// detach???
		i++;
	}
}
