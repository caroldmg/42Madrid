/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:21:06 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/11 17:32:01 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(char **argv)
{
	t_philo *philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (error_msg(ERROR_MALLOC));
	philo->num_of_philo = argv[1];
	philo->time_to_die = argv[2];
	philo->time_to_eat = argv[3];
	philo->time_to_sleep = argv[4];
	if (argv[5])
		philo->nb_meals_to_eat = argv[5];
	
}