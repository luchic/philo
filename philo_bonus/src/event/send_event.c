/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:41:50 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 19:36:25 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdio.h>

void	send_event(t_data *data, t_event event)
{
	if (!data || !data->queue)
		return ;
	pthread_mutex_lock(&data->queue->lock);
	ent_queue(data->queue, event);
	pthread_mutex_unlock(&data->queue->lock);
}
