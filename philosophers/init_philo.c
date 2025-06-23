/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:32:26 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 21:14:02 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_prgm_data(char **argv, t_philo *program)
{
	program->num_philo = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		program->nb_meals_to_eat = ft_atoi(argv[5]);
	else
		program->nb_meals_to_eat = -1;
}

pthread_mutex_t	*init_fork_mutex(t_philo *data)
{
	int				i;
	int				nb;
	pthread_mutex_t *forks;

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
		return (NULL); //gestion de error
	while (i < num_philo)
	{
		last_meal[i] = ft_get_time_ms();
		i++;
	}
	return (last_meal);
}

void	init_philo(t_philo *data, t_philo *philosophers, pthread_mutex_t *forks, long long *last_meal)
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
		// philosophers[i].num_forks = data->num_philo;
		philosophers[i].num_philo = data->num_philo;
		philosophers[i].fork_mutex = forks;
		i++;
	}
	free(data);
}

t_philo *get_philo_data(t_philo	*data)
{
	pthread_mutex_t	*forks;
	long long		*last_meal;
	t_philo			*philosophers;

	philosophers = ft_calloc(data->num_philo, sizeof(t_philo));
	if (!philosophers)
		return (NULL); //gestionar error
	forks = init_fork_mutex(data);
	last_meal = init_last_meal(data->num_philo);
	init_philo(data, philosophers, forks, last_meal);
	return (philosophers);
}

t_philo	*create_program(char **argv)
{
	t_philo	*program;
	t_philo	*philosophers;

	program = ft_calloc(1, sizeof(t_philo));
	if (!program)
		return (NULL); //error msg
	init_prgm_data(argv, program);
	// printf("program --> num_philo --> %d \n", program->num_philo);
	philosophers = get_philo_data(program);
	if (!philosophers)
	{ //revisar esta gestion, que es que lo que hace es ir retornando null y creo que yo retorno otro valor cuando gestiono con error_msg
		free(program);
		return (NULL);
	}
	return (philosophers);
}
