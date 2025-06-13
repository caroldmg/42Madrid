/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:12:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/13 19:51:16 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
// # include <limits.h>

// DEFINES
# define NO_ERROR 0
# define ERROR_MALLOC 1
# define BAD_ARGS -1
# define ERROR_THREAD -2
# define ARG_ER_MSG "Philo: argumentos no válidos. La estructura correcta es: \n \t./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"

/* typedef struct s_philo
{
	// info que te dan los args
	pthread_t		thread;
	int				id;

	// time
	size_t			start_time;
	size_t			last_meal;

	// 
	int				eating; //bool?
	int				meals_eaten;
	int				*dead; //bool

	// locks
	pthread_mutex_t	*r_fork; //estos son los enganches con el anterior y el siguiente
	pthread_mutex_t	*l_fork;
	pthread_mutex_t *write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_philo_table
{
	bool			dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_meals_to_eat;
	int				num_of_philo;
	long			start_time;
	
	t_philo			*philos;
}	t_philo_table; */


// estructura de https://github.com/zelhajou/ft_unix_philosophers/
typedef struct	s_philo
{
	int	id;
	// int	*meals_eaten;
	int				meals_eaten;
	int				nb_meals_to_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			*last_meal;
	int				num_forks; //??
	int				num_philo;
	pthread_t		philo_th;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*lock;
	long			start_time;
	bool			dead_flag;
}	t_philo;


// parsing
int		check_valid_args(int argc, char **argv);
bool	check_values(char **arg);
bool	check_is_num(char **arg);

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);

t_philo	*create_program(char **argv);
t_philo	*init_monitor(t_philo *philo);

// utils
long long	ft_get_time_ms(void);

int		error_msg(int value);


#endif

