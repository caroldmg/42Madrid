/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:13:41 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/19 17:17:35 by cde-migu         ###   ########.fr       */
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
		pthread_mutex_lock(monitor->lock);
		time = ft_get_time_ms() - monitor->last_meal[i];
		pthread_mutex_unlock(monitor->lock);
		if (time >= monitor->time_to_die)
		{
			ft_write_state(DEATH_MSG, &philo[i + 1]); //si esto funciona no tengo que hacer el ftprintdeath
			return (NULL);
		}
		if (i + 1 == monitor->num_philo)
			i = -1;
		i++;
	}
	return (NULL);
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

void	free_monitor(t_philo *monitor)
{
	pthread_mutex_destroy(monitor->lock);
	free(monitor->lock);
	free(monitor);
}

void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(philo->fork_mutex);
	free(philo->fork_mutex);
	free(philo->last_meal);
	pthread_mutex_destroy(philo->m_dead);
	free(philo->m_dead);
	free(philo);
}

void	clean_everything(t_philo *philo, t_philo *monitor)
{
	int i;

	i = 0;
	ft_usleep(philo->time_to_die + philo->time_to_eat + philo->time_to_sleep + 10); //darle tiempo para que acabe todo finiquitao
	// free lo del monitor por un lado y lo del philo por otro
	
}