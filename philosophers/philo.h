/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:12:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/25 12:40:14 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

// DEFINES
# define NO_ERROR 0
# define ERROR_MALLOC 1
# define BAD_ARGS -1
# define ERROR_THREAD -2
# define UNKNOWN_ERROR -3
# define INIT_ERROR -4

// COLORS
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0m"

// mensajes
# define ARG_ER_MSG "Philo: argumentos no válidos. La estructura correcta es: \n \
		./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]"
# define TAKE_FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEATH_MSG "died"

typedef struct s_philo
{
	int				id;
	int				*meals_eaten;
	int				nb_meals_to_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		*last_meal;
	int				num_philo;
	pthread_t		philo_th;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*lock;
	long			start_time;
	bool			dead_flag;
}	t_philo;

typedef struct s_all
{
	t_philo	*philosophers;
	t_philo	*monitor;
}	t_all;

// check_input.c
int			check_valid_args(int argc, char **argv);
bool		check_values(char **arg);
bool		check_is_num(char **arg);
void		init_prgm_data(char **argv, t_philo *program);

// libft_utils.c
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		*ft_calloc(size_t count, size_t size);
void		ft_putendl_fd(char *s, int fd);

// init_philo.c
t_philo		*create_program(char **argv);

// monitor.c
t_philo		*init_monitor(t_philo *philo);
void		link_philo_monitor(t_all *all);

// routine.c
void		*philo_routine(void *arg);
int			start_philo_life(t_philo *philo);
int			join_threads(t_philo *philo, t_philo *monitor);
void		kill_philos(t_philo *philosophers);
bool		is_dead(t_philo *philo);

// philo_states.c
void		pick_forks(t_philo *philo);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

// philo_death.c
void		*check_philo_death(void *philo);
void		clean_everything(t_all *all);
bool		still_eating(t_philo *monitor);
void		*print_and_kill(t_philo *monitor, t_philo *philos, int i);

// utils.c
long long	ft_get_time_ms(void);
void		ft_write_state(char *str, t_philo *philo);
void		ft_usleep(long long miliseconds, t_philo *philo);
void		ft_print_dead(int id, long long start);
int			ft_strlen(char *str);

// error_check.c
void		error_monitor(void);
int			error_msg(int value);

#endif