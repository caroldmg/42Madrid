/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:13:41 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/24 20:06:09 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_philo_death(void *all)
{
	int 		i;
	int			num;
	long long	time;
	t_philo		*monitor;
	t_philo		*philos;

	i = 0;
	monitor = ((t_all *)all)->monitor;
	philos = ((t_all *)all)->philosophers;
	num = monitor->num_philo;
	// ft_usleep(10);
	while (i < num && still_eating(monitor))
	{
		pthread_mutex_lock(monitor->lock);
		time = ft_get_time_ms() - monitor->last_meal[i];
		pthread_mutex_unlock(monitor->lock);
		if (time >= monitor->time_to_die)
		{
			pthread_mutex_lock(monitor->lock);
			ft_print_dead(i + 1, monitor->start_time);
			kill_philos(philos);
			pthread_mutex_unlock(monitor->lock);
			return (NULL);
		}
		if (i + 1 == num)
			i = -1;
		i++;
	}
	kill_philos(philos);
	return (NULL);
}

//// @brief la funciñon "still_eating" comprueba si los filósofos han realizado todas las comidas(número de ciclos) esperadas, revisando uno a uno todos los filósofos. Además, antes de retornar deja el mutex bloqueado para asegurarnos que nadie más escribe en la terminal
/// @param monitor ese el elemento externo que "vigila" o "monitoriza" las acciones de los filósofos, asegurando que estos no se comunican entre sí
/// @return retorna "true" si aún le quedan comidas por realizar, y false si ya las ha completado
bool	still_eating(t_philo *monitor)
{
	int	i;

	i = 0;
	if (monitor->nb_meals_to_eat == -1)
		return (true);
	while (i < monitor->num_philo)
	{
		pthread_mutex_lock(monitor->lock);
		if (monitor->meals_eaten[i] < monitor->nb_meals_to_eat)
		{
			pthread_mutex_unlock(monitor->lock);
			return (true);
		}
		pthread_mutex_unlock(monitor->lock);
		i++;
	}
	return (false);
}

void	ft_print_dead(int id, long long start)
{
	long curr_time;
	
	curr_time = ft_get_time_ms() - start;
	printf("%04ld \t %d died \n",curr_time, id);
}

void	ft_finish_eating(long long start)
{
	long curr_time;
	
	curr_time = ft_get_time_ms() - start;
	printf("%04ld \t they have finished eating \n",curr_time, id);
}
