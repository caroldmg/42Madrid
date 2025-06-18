/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:55:33 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/18 17:12:45 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (!is_dead(philo)) //crear funcion que mire si hay alguno muerto?
	{
		pick_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_mutex[philo->id - 1]);
	if (philo->id == 1)
		pthread_mutex_lock(&philo->fork_mutex[philo->num_philo - 1]);
	else
		pthread_mutex_lock(&philo->fork_mutex[philo->id - 2]);
	ft_write_state(TAKE_FORK_MSG, philo);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_mutex[philo->id - 1]);
	if (philo->id == 1)
		pthread_mutex_unlock(&philo->fork_mutex[philo->num_philo - 1]);
	else
		pthread_mutex_unlock(&philo->fork_mutex[philo->id - 2]);
}

void	philo_eat(t_philo *philo)
{
	ft_write_state(EAT_MSG, philo);
	philo->last_meal[philo->id - 1] = ft_get_time_ms();
	philo->meals_eaten[philo->id - 1]++;
	ft_usleep(philo->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	ft_write_state(SLEEP_MSG, philo);
	ft_usleep(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	ft_write_state(THINK_MSG, philo);
}
