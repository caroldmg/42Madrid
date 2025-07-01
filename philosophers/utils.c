/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:15:53 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/01 12:23:48 by cde-migu         ###   ########.fr       */
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
	char	*color[3];

	if (is_dead(philo))
		return ;
	color[0] = RED;
	color[1] = PURPLE;
	color[2] = YELLOW;
	time = ft_get_time_ms() - philo->start_time;
	pthread_mutex_lock(philo->lock);
	write(1, color[philo->id % 3], ft_strlen(color[philo->id % 3]));
	printf("%04ld \t %d %s \n", time, philo->id, str);
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
	return (philo->dead_flag);
}
