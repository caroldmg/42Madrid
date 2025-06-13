/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:21:06 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/13 12:13:34 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// t_philo	*init_philo(char **argv, int id)
// {
// 	t_philo *philo;

// 	philo = ft_calloc(1, sizeof(t_philo));
// 	if (!philo)
// 		return (error_msg(ERROR_MALLOC));
// 	philo->num_of_philo = ft_atoi(argv[1]);
// 	philo->time_to_die = ft_atoi(argv[2]);
// 	philo->time_to_eat = ft_atoi(argv[3]);
// 	philo->time_to_sleep = ft_atoi(argv[4]);
// 	if (argv[5])
// 		philo->nb_meals_to_eat = ft_atoi(argv[5]);
// 	return (philo);
// }

t_philo_table	*init_table(char **argv)
{

	t_philo_table *table;

	table = calloc(1, sizeof(t_philo_table));
	if (!table)
		error_msg(ERROR_MALLOC);
	if (init_data != NO_ERROR)
		error_msg(ERROR_THREAD); //TODO: gestion de errores con liberacion
	
	
}

int	init_data(char **argv, t_philo_table *table)
{
	table->num_of_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->nb_meals_to_eat = ft_atoi(argv[5]);
	else
		table->nb_meals_to_eat = -1; //no sé si esto es neccesario
	table->dead_flag = false;
	if (pthread_mutex_init(&table->dead_lock, NULL) != NO_ERROR)
		return (error_msg(ERROR_THREAD));
	if (pthread_mutex_init(&table->meal_lock, NULL) != NO_ERROR)
		return (ERROR_THREAD);
	if (pthread_mutex_init(&table->write_lock, NULL) != NO_ERROR)
		return (ERROR_THREAD);
	return (NO_ERROR);
}
