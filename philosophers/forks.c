/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:21 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/08 14:08:04 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_fork_mutex(t_philo *data)
{
	int				i;
	int				nb;
	pthread_mutex_t	*forks;

	i = 0;
	nb = data->num_philo;
	forks = ft_calloc(nb, sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (i < nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

pthread_mutex_t	*create_fork(void)
{
	pthread_mutex_t	*fork;

	fork = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!fork)
		return (NULL);
	pthread_mutex_init(fork, NULL);
	return (fork);
}

void	connect_forks(t_philo *current, int i, t_philo *philo_array)
{
	if (i == 0)
	{
		current->r_fork = create_fork();
		if (current->num_philo > 1)
			current->l_fork = create_fork();
		else
			current->l_fork = NULL;
	}
	else if (i == current->num_philo - 1)
	{
		current->l_fork = philo_array[i - 1].r_fork;
		current->r_fork = philo_array[0].l_fork;
	}
	else
	{
		current->l_fork = philo_array[i - 1].r_fork;
		current->r_fork = create_fork();
	}
}

void	lock_fork(pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
}

void	unlock_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}
