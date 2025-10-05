/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:54:18 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/05 18:46:58 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void	set_status(t_philo *philo, t_state state)
{
	t_event	event;

	event.timestamp = get_delta_ms(philo->data);
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

static void	end_rutine(t_philo *philo)
{
	t_event	event;

	memset(&event, 0, sizeof(t_event));
	event.philo_id = philo->id;
	event.type = END_ITER;
	send_event(philo->data, event);
}

void	run_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->iterations = 0;
	if (philo->id % 2 != 0)
		(usleep(200), thinking(philo));
	if (philo->data->count % 2 != 0 && philo->data->count - 1== philo->id)
		(usleep(200), thinking(philo));
	while (1)
	{
		philo->iterations++;
		if (eating(philo))
			return ;
		if (get_dead_status(philo->data))
			return ;
		if (sleeping(philo))
			return ;
		if (philo->data->max_iter > 0
			&& philo->iterations >= philo->data->max_iter)
			break ;
		thinking(philo);
		if (get_dead_status(philo->data))
			return ;
	}
	end_rutine(philo);
}
