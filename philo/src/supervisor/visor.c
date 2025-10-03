/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:26:33 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/02 20:53:27 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdio.h>
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

// static void	__print_if_changed_status(t_data *data)
// {
// 	t_event	events[MAX_SIZE];
// 	int		is_new_event;
// 	int		i;
// 	int		j;

// 	is_new_event = 0;
// 	i = 0;
// 	pthread_mutex_lock(&data->queue->lock);
// 	while (!is_empty(data->queue))
// 	{
// 		is_new_event = 1;
// 		events[i] = peek(data->queue);
// 		if (events[i].type != IS_EMPTY)
// 			det_queue(data->queue);
// 		i++;
// 	}
// 	pthread_mutex_unlock(&data->queue->lock);
// 	j = -1;
// 	if (is_new_event)
// 	{
// 		while (++j < i)
// 			print_message(events[j]);
// 	}
// }

static void	print_if_changed_status(t_data *data)
{
	int	n;

	t_event batch[MAX_SIZE]; // small stack buffer
	n = 0;
	pthread_mutex_lock(&data->queue->lock);
	while (!is_empty(data->queue))
	{
		batch[n++] = peek(data->queue);
		det_queue(data->queue);
	}
	pthread_mutex_unlock(&data->queue->lock);
	for (int i = 0; i < n; i++)
		print_message(batch[i]);
}

int	run_supervisor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (!data)
		return (1);
	usleep(300);
	while (1)
	{
		print_if_changed_status(data);
		usleep(1000);
	}
	return (0);
}
