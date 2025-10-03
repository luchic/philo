/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:26:33 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 19:37:01 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Should be run in a separate thread
static void	print_message(t_event event)
{
	if (event.type == PHILO_THINKING)
		printf("%lu %d is thinking\n", event.timestamp, event.philo_id);
	else if (event.type == PHILO_EATING)
		printf("%lu %d is eating\n", event.timestamp, event.philo_id);
	else if (event.type == PHILO_SLEEPING)
		printf("%lu %d is sleeping\n", event.timestamp, event.philo_id);
	else if (event.type == FORK_TAKEN)
		printf("%lu %d has taken a fork\n", event.timestamp, event.philo_id);
}

static int	handle_events(t_data *data, t_life_time *life_times)
{
	t_event	batch[MAX_SIZE];
	int		n;
	int		i;

	n = get_event(data, batch, MAX_SIZE);
	if (n == 0)
		return (1);
	i = -1;
	while (++i < n)
	{
		if (batch[i].type == END_ITER)
		{
			life_times[batch[i].philo_id].id = -1;
			continue ;
		}
		if (batch[i].type == PHILO_EATING)
			update_meal_time(life_times, batch[i].philo_id, batch[i].timestamp
				+ data->start_time);
		print_message(batch[i]);
	}
	return (1);
}

static int	is_iter_end(t_life_time *life_times, int count)
{
	int	i;
	int	ended;

	i = -1;
	ended = 1;
	while (++i < count)
	{
		if (life_times[i].id != -1)
		{
			ended = 0;
			break ;
		}
	}
	return (ended);
}

int	run_supervisor(void *arg)
{
	t_data		*data;
	t_life_time	*life_times;

	data = (t_data *)arg;
	if (!data)
		return (1);
	if (!init_life_times(data, &life_times))
		return (set_death(data, 1), 1);
	usleep(200);
	while (1)
	{
		if (is_iter_end(life_times, data->count))
			break ;
		if (update_dead_status_if_dead(data, life_times))
		{
			printf("%lu %d died\n", get_delta_ms(data), life_times[0].id);
			break ;
		}
		if (!handle_events(data, life_times))
			break ;
		usleep(1000);
	}
	free(life_times);
	return (0);
}
