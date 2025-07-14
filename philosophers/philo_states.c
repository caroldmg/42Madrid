/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:20:33 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/14 17:36:37 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		lock_fork(philo->l_fork);
		ft_write_state(TAKE_FORK_MSG, philo);
		lock_fork(philo->r_fork);
		ft_write_state(TAKE_FORK_MSG, philo);
	}
	else
	{
		lock_fork(philo->r_fork);
		ft_write_state(TAKE_FORK_MSG, philo);
		lock_fork(philo->l_fork);
		ft_write_state(TAKE_FORK_MSG, philo);
	}
}

void	leave_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		unlock_fork(philo->r_fork);
		unlock_fork(philo->l_fork);
	}
	else
	{
		unlock_fork(philo->l_fork);
		unlock_fork(philo->r_fork);
	}
}

void	philo_eat(t_philo *philo)
{
	ft_write_state(EAT_MSG, philo);
	pthread_mutex_lock(philo->lock);
	philo->last_meal[philo->id - 1] = ft_get_time_ms();
	philo->meals_eaten[philo->id - 1]++;
	pthread_mutex_unlock(philo->lock);
	ft_usleep(philo->time_to_eat, philo);
}

void	philo_sleep(t_philo *philo)
{
	ft_write_state(SLEEP_MSG, philo);
	ft_usleep(philo->time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	ft_write_state(THINK_MSG, philo);
}
