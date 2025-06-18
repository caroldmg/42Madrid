/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:15:53 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/18 19:49:09 by cde-migu         ###   ########.fr       */
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

void	ft_write_state(char *str, t_philo *philo)
{
	long	time;
	
	time = ft_get_time_ms() - philo->start_time;
	pthread_mutex_lock(philo->lock);
	if (!is_dead(philo))
		printf("%09ld %d %s", time, philo->id, str);
	pthread_mutex_unlock(philo->lock);
}

void	ft_print_dead(char *str, int id)
{
	
}

void	ft_usleep(long long miliseconds)
{
	long long	start;

	start = 0;
	start = ft_get_time_ms();
	while ((ft_get_time_ms() - start) < miliseconds)
		usleep(100);
}
