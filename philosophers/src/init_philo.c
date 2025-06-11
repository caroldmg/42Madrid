/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:21:06 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/11 18:12:25 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(char **argv, int id)
{
	t_philo *philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (error_msg(ERROR_MALLOC));
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nb_meals_to_eat = ft_atoi(argv[5]);
	return (philo);
}

t_philo_table	*init_table(char **argv)
{
	int i;
	int num_philo;
	t_philo_table *table;

	i = 0;
	num_philo = ft_atoi(argv[1]);
	table = calloc(1, sizeof(t_philo_table));
	while(i < num_philo)
	{
		init_philo()
	}
	free(num_philo);
}