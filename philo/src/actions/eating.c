/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:19:46 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/05 13:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <unistd.h>

static void	is_fork_taken(t_philo *philo)
{
	t_event	event;

	event.timestamp = get_delta_ms(philo->data);
	event.type = FORK_TAKEN;
	event.philo_id = philo->id;
	send_event(philo->data, event);
}

static void	lock_eating(t_philo *philo)
{
	if (philo->data->count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		is_fork_taken(philo);
		while (!get_dead_status(philo->data))
			usleep(100);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		is_fork_taken(philo);
		pthread_mutex_lock(philo->left_fork);
		is_fork_taken(philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		is_fork_taken(philo);
		pthread_mutex_lock(philo->right_fork);
		is_fork_taken(philo);
	}
}

static void	unlock_eating(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eating(t_philo *philo)
{
	int	is_dead;

	lock_eating(philo);
	set_status(philo, EATING);
	is_dead = sleep_ms(philo, philo->data->time_to_eat);
	unlock_eating(philo);
	return (is_dead);
}
