/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:15:53 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/23 22:04:40 by cde-migu         ###   ########.fr       */
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

void	ft_print_dead(int id, long long start)
{
	long long curr_time;
	
	curr_time = ft_get_time_ms() - start;
	printf("%09lld \t %d died \n",start, id);
}

void	ft_usleep(long long miliseconds)
{
	long long	start;

	start = ft_get_time_ms();
	while ((ft_get_time_ms() - start) < miliseconds)
		usleep(100);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
