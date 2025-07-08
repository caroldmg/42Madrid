/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:20:33 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/08 12:43:48 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	pick_forks(t_philo *philo)
// {
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(&philo->fork_mutex[philo->id - 1]);
// 		ft_write_state(TAKE_FORK_MSG, philo, RED);
// 		pthread_mutex_lock(&philo->fork_mutex[philo->id - 2]);
// 		ft_write_state(TAKE_FORK_MSG, philo, RED);
// 	}
// 	else
// 	{
// 		if (philo->id == 1)
// 			pthread_mutex_lock(&philo->fork_mutex[philo->num_philo - 1]);
// 		else
// 			pthread_mutex_lock(&philo->fork_mutex[philo->id - 2]);
// 		ft_write_state(TAKE_FORK_MSG, philo, RED);
// 		pthread_mutex_lock(&philo->fork_mutex[philo->id - 1]);
// 		ft_write_state(TAKE_FORK_MSG, philo, RED);
// 	}
// }
void	lock_fork(pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
}

void	unlock_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

void	pick_forks(t_philo *philo)
{
	if (!philo->l_fork || !philo->r_fork)
		return ;
	if (philo->id % 2 == 0)
	{
		lock_fork(philo->l_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
		lock_fork(philo->r_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
	}
	else
	{
		lock_fork(philo->r_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
		lock_fork(philo->l_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
	}
}

// void	leave_forks(t_philo *philo)
// {
// 	pthread_mutex_unlock(&philo->fork_mutex[philo->id - 1]);
// 	if (philo->id == 1)
// 		pthread_mutex_unlock(&philo->fork_mutex[philo->num_philo - 1]);
// 	else
// 		pthread_mutex_unlock(&philo->fork_mutex[philo->id - 2]);
// }

void	leave_forks(t_philo *philo)
{
	
	if (philo->id % 2 == 0)
	{
		unlock_fork(philo->r_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
		unlock_fork(philo->l_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
	}
	else
	{
		unlock_fork(philo->l_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
		unlock_fork(philo->r_fork);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
	}
}

void	philo_eat(t_philo *philo)
{
	ft_write_state(EAT_MSG, philo, GREEN);
	// pthread_mutex_lock(philo->data_mutex);
		pthread_mutex_lock(philo->lock);

	philo->last_meal[philo->id - 1] = ft_get_time_ms();
	philo->meals_eaten[philo->id - 1]++;
		pthread_mutex_unlock(philo->lock);

	// pthread_mutex_unlock(philo->data_mutex);
	ft_usleep(philo->time_to_eat, philo);
}

void	philo_sleep(t_philo *philo)
{
	ft_write_state(SLEEP_MSG, philo, BLUE);
	ft_usleep(philo->time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	ft_write_state(THINK_MSG, philo, PURPLE);
}
