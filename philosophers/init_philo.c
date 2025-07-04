/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:32:26 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/04 13:03:35 by cde-migu         ###   ########.fr       */
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

long long	*init_last_meal(int num_philo)
{
	int			i;
	long long	*last_meal;

	i = 0;
	last_meal = ft_calloc(num_philo, sizeof(size_t));
	if (!last_meal)
		return (NULL);
	while (i < num_philo)
	{
		last_meal[i] = ft_get_time_ms();
		i++;
	}
	return (last_meal);
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

void connect_forks(t_philo *current, int i, t_philo *philo_array)
{
	if (i == 0)
	{
		current->r_fork = create_fork();
		if (current->num_philo > 1)
			current->l_fork = create_fork();
		else
			current->l_fork = create_fork();
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

void	init_philo(t_philo *data, t_philo *philosophers, long long *last_meal)
{
	int	i;
	int	*meals;

	i = 0;
	meals = ft_calloc(data->num_philo, sizeof(int));
	if (!meals)
		return ;
	while (i < data->num_philo)
	{
		philosophers[i].id = i + 1;
		philosophers[i].meals_eaten = meals;
		philosophers[i].time_to_die = data->time_to_die;
		philosophers[i].time_to_eat = data->time_to_eat;
		philosophers[i].time_to_sleep = data->time_to_sleep;
		philosophers[i].nb_meals_to_eat = data->nb_meals_to_eat;
		philosophers[i].last_meal = last_meal;
		philosophers[i].dead_flag = false;
		philosophers[i].num_philo = data->num_philo;
		// philosophers[i].fork_mutex = forks;
		philosophers[i].data_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(philosophers[i].data_mutex, NULL);
		connect_forks(&philosophers[i], i, philosophers);
		i++;
	}
	free(data);
}

t_philo	*get_philo_data(t_philo	*data)
{
	// pthread_mutex_t	*forks;
	long long		*last_meal;
	t_philo			*philosophers;

	philosophers = ft_calloc(data->num_philo, sizeof(t_philo));
	if (!philosophers)
		return (NULL);
	// forks = init_fork_mutex(data);
	last_meal = init_last_meal(data->num_philo);
	init_philo(data, philosophers, last_meal);
	
	return (philosophers);
}

t_philo	*create_program(char **argv)
{
	t_philo	*program;
	t_philo	*philosophers;

	program = ft_calloc(1, sizeof(t_philo));
	if (!program)
		return (NULL);
	init_prgm_data(argv, program);
	philosophers = get_philo_data(program);
	if (!philosophers)
	{
		free(program);
		return (NULL);
	}
	return (philosophers);
}
