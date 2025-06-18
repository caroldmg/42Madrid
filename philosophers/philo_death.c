/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:13:41 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/18 17:57:54 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	bool is_dead;
	pthread_mutex_lock(&philo->m_dead);
	is_dead = philo->dead_flag;
	pthread_mutex_unlock(&philo->m_dead);
	return (is_dead);
}

void	*check_philo_death(t_philo *philo)
{
	t_philo		*monitor;
	int 		i;
	long long	time;

	i = 0;
	monitor = philo;
	while (i < monitor->num_philo && check_meals_eaten(monitor))
	{
		
	}
}

int	kill_philo(t_philo *philo)
{
	
}

void	check_deaths(void *arg)
{
	
}

/// @brief la funciñon "check_meals_eaten" comprueba si los filósofos han realizado todas las comidas(número de ciclos) esperadas, revisando uno a uno todos los filósofos. Además, antes de retornar deja el mutex bloqueado para asegurarnos que nadie más escribe en la terminal
/// @param monitor ese el elemento externo que "vigila" o "monitoriza" las acciones de los filósofos, asegurando que estos no se comunican entre sí
/// @return retorna "true" si aún le quedan comidas por realizar, y false si ya las ha completado
bool	check_meals_eaten(t_philo *monitor)
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