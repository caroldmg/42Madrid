/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:12:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/19 13:09:00 by cde-migu         ###   ########.fr       */
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

// mensajes
# define ARG_ER_MSG "Philo: argumentos no válidos. La estructura correcta es: \n \t./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"
# define TAKE_FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEATH_MSG "died"

// estructura de https://github.com/zelhajou/ft_unix_philosophers/
typedef struct	s_philo
{
	int	id;
	// int	*meals_eaten;
	int				*meals_eaten;
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
	pthread_mutex_t *m_dead;
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
void	link_philo_monitor(t_philo *philo, t_philo *monitor);

// routine
void	philo_routine(void *arg);
int		wait_threads(t_philo **philosophers, t_philo *monitor);
int		start_philo_life(t_philo *philo);

// status
void	pick_forks(t_philo *philo);
void	leave_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// death
bool	is_dead(t_philo *philo);
void	*check_philo_death(t_philo *philo);


// utils
long long	ft_get_time_ms(void);
void		ft_write_state(char *str, t_philo *philo);
void		ft_usleep(long long miliseconds);
void	ft_print_dead(int id, long long start);


int		error_msg(int value);


#endif

