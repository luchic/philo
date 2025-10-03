/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:54:18 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/02 21:36:38 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <sys/time.h>
#include <unistd.h>

void	set_status(t_philo *philo, t_state state)
{
	t_event			event;

	event.timestamp = now_ms() - philo->data->start_time;
	event.state = state;
	if (state == THINKING)
		event.type = PHILO_THINKING;
	else if (state == EATING)
		event.type = PHILO_EATING;
	else if (state == SLEEPING)
		event.type = PHILO_SLEEPING;
	event.philo_id = philo->id;
	send_event(philo->data, event);
}

void	run_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->iterations = 0;
	if (philo->id % 2 != 0)
	{
		usleep(200);
		thinking(philo);
	}
	while (1)
	{
		philo->iterations++;
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (philo->data->max_iter > 0
			&& philo->iterations >= philo->data->max_iter)
			break ;
	}
	return ;
}
