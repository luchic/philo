/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:26:17 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/01 20:29:33 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

static void	close_forks(t_data *data, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&data->forks[i]);
}

static void	close_state_locks(t_data *data, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&data->philos[i].state_lock);
}

int	init_forks(t_data *data)
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
	i = -1;
	while (++i < data->count)
	{
		if (pthread_mutex_init(&data->philos[i].state_lock, NULL) != 0)
		{
			close_state_locks(data, i);
			close_forks(data, data->count);
			return (0);
		}
	}
	return (1);
}
