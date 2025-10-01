/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:54:18 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/01 20:23:08 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

void	set_status(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->state_lock);
	philo->state = state;
	philo->is_state_changed = 1;
	pthread_mutex_unlock(&philo->state_lock);
}

void	run_action(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	data = (t_data *)arg;
	philo = (t_philo *)arg;
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return ;
}

