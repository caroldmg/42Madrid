/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:12:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/11 17:30:41 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "libft.h"

// DEFINES
# define NO_ERROR 0
# define ERROR_MALLOC 1
# define BAD_ARGS -1
# define ARG_ER_MSG "Philo: argumentos no válidos. La estructura correcta es: \n \t./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"

typedef struct s_philo
{
	// info que te dan los args
	int				id;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_meals_to_eat;
	int				num_of_philo;

	// 
	int				eating; //bool?
	int				meals_eaten;
	int				dead; //bool
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

int		check_valid_args(int argc, char **argv);
int		error_msg(int value);


bool	check_is_num(char **arg);
bool	check_values(char **arg);



#endif

