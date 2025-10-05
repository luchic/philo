/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:26:17 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 11:32:44 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

static void	close_forks(t_data *data, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&data->forks[i]);
}

static int	open_mutex_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			close_forks(data, i);
			return (0);
		}
	}
	return (1);
}

int	init_forks(t_data *data)
{
	if (!open_mutex_forks(data))
		return (0);
	if (pthread_mutex_init(&data->queue->lock, NULL) != 0)
	{
		close_forks(data, data->count);
		return (0);
	}
	if (pthread_mutex_init(&data->is_dead_lock, NULL) != 0)
	{
		close_forks(data, data->count);
		pthread_mutex_destroy(&data->queue->lock);
		return (0);
	}
	return (1);
}
