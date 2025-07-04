/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:55:33 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/04 13:03:11 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	// t_all *all;
	t_philo	*philo;
	
	// all = (t_all *)arg;
	// pthread_mutex_lock(all->monitor->lock);
	// philo = &all->philo[all->i];
	// pthread_mutex_unlock(all->monitor->lock);
	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(10);
	pthread_mutex_lock(philo->data_mutex);
	philo->last_meal[philo->id - 1] = ft_get_time_ms();
	pthread_mutex_unlock(philo->data_mutex);
	while (is_dead(philo) == false)
	{
		pick_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
		// pthread_mutex_lock(philo->death_mutex);
		// philo->dead_flag = all->monitor->dead_flag;
		// pthread_mutex_unlock(philo->death_mutex);
		// if (philo->id % 2 != 0)
		// 	usleep(10);
	}
	return (NULL);
}

void	*just_the_one(void *arg)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)arg;
	while (is_dead(philo) == false)
	{
		// pthread_mutex_lock(philo->fork_mutex);
		ft_write_state(TAKE_FORK_MSG, philo, RED);
		// pthread_mutex_unlock(philo->fork_mutex);
		pthread_mutex_lock(philo->lock);
		ft_usleep(philo->time_to_die, philo);
		time = ft_get_time_ms() - philo->start_time;
		printf("%lld \t %d died \n", time, philo->id);
		pthread_mutex_unlock(philo->lock);
		return (NULL);
	}
	return (NULL);
}

int	start_philo_life(t_philo *philo)
{
	int		i;
	int		num_philo;
	int		ret_code;
	long	start_time;

	i = 0;
	ret_code = 0;
	num_philo = philo->num_philo;
	start_time = ft_get_time_ms();
	if (num_philo == 1)
	{
		philo[i].start_time = start_time;
		philo->last_meal[philo->id - 1] = ft_get_time_ms();
		pthread_create(&philo->philo_th, NULL, just_the_one, &philo[i]);
		return (1);
	}
	while (i < num_philo)
	{
		philo[i].start_time = start_time;
		if (pthread_create \
			(&philo[i].philo_th, NULL, philo_routine, &philo[i]) \
			!= NO_ERROR)
			ret_code = 2;
		i++;
	}
	return (ret_code);
}

int	join_threads(t_all *all)
{
	int		i;
	int		num;
	int		ret_code;
	t_philo	*monitor;
	t_philo	*philo;

	i = 0;
	ret_code = 0;
	monitor = all->monitor;
	philo = all->philo;
	num = monitor->num_philo;
	pthread_create(&all->monitor->philo_th, NULL, check_philo_death, all);
	pthread_join(all->monitor->philo_th, NULL);
	while (i < num)
	{
		if (pthread_join(philo[i].philo_th, NULL) != NO_ERROR)
			ret_code = 1;
		i++;
	}
	return (ret_code);
}

void	kill_philos(t_philo *philosophers)
{
	int	i;
	int	nb;

	i = 0;
	nb = philosophers->num_philo;
	while (i < nb)
	{
		pthread_mutex_lock(philosophers[i].data_mutex);
		philosophers[i].dead_flag = true;
		pthread_mutex_unlock(philosophers[i].data_mutex);
		i++;
	}
	// pthread_mutex_unlock(philosophers->lock);
}
