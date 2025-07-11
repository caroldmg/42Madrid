/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:15:53 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/04 16:07:13 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time_ms(void)
{
	struct timeval	current_time;
	long long		miliseconds;

	if (gettimeofday(&current_time, NULL) == -1)
		return (1);
	miliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (miliseconds);
}

void	ft_write_state(char *str, t_philo *philo, char *color)
{
	long	time;

	if (is_dead(philo))
		return ;
	pthread_mutex_lock(philo->lock);
	time = ft_get_time_ms() - philo->start_time;
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->lock);
		return ;
	}
	write(1, color, ft_strlen(color));
	printf("%ld %d %s\n", time, philo->id, str);
	write(1, RESET, ft_strlen(RESET));
	pthread_mutex_unlock(philo->lock);
}

void	ft_usleep(long long miliseconds, t_philo *philo)
{
	long long	start;

	start = ft_get_time_ms();
	while ((ft_get_time_ms() - start) < miliseconds && !is_dead(philo))
		usleep(100);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	is_dead(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(philo->data_mutex);
	flag = philo->dead_flag;
	pthread_mutex_unlock(philo->data_mutex);
	return (flag);
}
