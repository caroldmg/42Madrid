/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:13:41 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/04 12:01:46 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_philo_death(void *all)
{
	int			i;
	long long	time;
	t_philo		*monitor;
	t_philo		*philos;

	i = 0;
	monitor = ((t_all *)all)->monitor;
	philos = ((t_all *)all)->philo;
	while (i < monitor->num_philo && still_eating(monitor))
	{
		pthread_mutex_lock(monitor->data_mutex);
		time = ft_get_time_ms() - monitor->last_meal[i];
		if (time >= monitor->time_to_die)
			return (print_and_kill(monitor, philos, i));
		if (i + 1 == monitor->num_philo)
			i = -1;
		i++;
		pthread_mutex_unlock(monitor->data_mutex);
	}
	pthread_mutex_lock(monitor->lock);
	kill_philos(philos);
	pthread_mutex_unlock(monitor->lock);
	return (NULL);
}

bool	still_eating(t_philo *monitor)
{
	int	i;

	i = 0;
	if (monitor->nb_meals_to_eat == -1)
		return (true);
	while (i < monitor->num_philo)
	{
		pthread_mutex_lock(monitor->data_mutex);
		if (monitor->meals_eaten[i] < monitor->nb_meals_to_eat)
		{
			pthread_mutex_unlock(monitor->data_mutex);
			return (true);
		}
		pthread_mutex_unlock(monitor->data_mutex);
		i++;
	}
	printf("\n ---------- \n \n");
	printf("Todos los filosofos han comido ya \
%d veces y están llenos 🍝 \n", monitor->nb_meals_to_eat);
	return (false);
}

void	*print_and_kill(t_philo *monitor, t_philo *philos, int i)
{
	// pthread_mutex_lock(monitor->lock);
	ft_print_dead(i + 1, monitor->start_time);
	monitor->dead_flag = true;
	kill_philos(philos);
	pthread_mutex_unlock(monitor->data_mutex);
	return (NULL);
}

void	ft_print_dead(int id, long long start)
{
	long	curr_time;

	curr_time = ft_get_time_ms() - start;
	printf("%04ld %d died \n", curr_time, id);
}

void	ft_finish_eating(long long start)
{
	long	curr_time;

	curr_time = ft_get_time_ms() - start;
	printf("%04ld \t they have finished eating \n", curr_time);
}
