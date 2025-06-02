/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:12:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/02 19:42:24 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	// info que te dan los args
	int				id;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_meals_to_eat;
	int				num_of_philo;

	// 
	int				eating; //bool?
	int				meals_eaten;
	int				dead;
	// time
	size_t			start_time;
	size_t			last_meal;

	// locks
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t *write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;


#endif
