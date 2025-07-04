/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:42:28 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/04 13:02:59 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_monitor(t_philo *philo)
{
	t_philo	*monitor;

	monitor = ft_calloc(1, sizeof(t_philo));
	if (!monitor)
		return (NULL);
	monitor->id = 0;
	monitor->nb_meals_to_eat = philo->nb_meals_to_eat;
	monitor->time_to_die = philo->time_to_die;
	monitor->time_to_eat = philo->time_to_die;
	monitor->time_to_sleep = philo->time_to_sleep;
	monitor->meals_eaten = philo->meals_eaten;
	monitor->last_meal = philo->last_meal;
	monitor->num_philo = philo->num_philo;
	// monitor->fork_mutex = NULL;
	monitor->lock = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor->lock, NULL);
	monitor->data_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor->data_mutex, NULL);
	return (monitor);
}

void	link_philo_monitor(t_all *all)
{
	int		i;
	t_philo	*monitor;
	t_philo	*philo;

	i = 0;
	monitor = all->monitor;
	philo = all->philo;
	while (i < monitor->num_philo)
	{
		philo[i].lock = monitor->lock;
		i++;
	}
	monitor->start_time = ft_get_time_ms();
}

void	clean_everything(t_all *all)
{
	int		i;
	t_philo	*philo;
	t_philo	*monitor;

	i = 0;
	monitor = all->monitor;
	philo = all->philo;
	// pthread_mutex_destroy(philo->fork_mutex);
	// free(philo->fork_mutex);
	free(philo->last_meal);
	free(philo->meals_eaten);
	pthread_mutex_destroy(philo->lock);
	free(philo->lock);
	philo = NULL;
	free(monitor);
	free(all);
}
