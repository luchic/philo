/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:44:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 10:05:38 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdio.h>

int	get_event(t_data *data, t_event *events, int max_size)
{
	t_event	event;
	int		i;

	i = 0;
	pthread_mutex_lock(&data->queue->lock);
	while (!is_empty(data->queue))
	{
		event = peek(data->queue);
		det_queue(data->queue);
		events[i++] = event;
	}
	pthread_mutex_unlock(&data->queue->lock);
	return (i);
}
