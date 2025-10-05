/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:07:04 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 11:21:30 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdlib.h>
#include <string.h>

static int	allocate_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->count);
	if (!data->philos)
		return (0);
	memset(data->philos, 0, sizeof(t_philo) * data->count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (free(data->philos), 0);
	memset(data->forks, 0, sizeof(pthread_mutex_t) * data->count);
	return (1);
}

int	init_data(t_data *data)
{
	if (!data)
		return (0);
	if (!allocate_data(data))
		return (0);
	if (!init_queue(data))
		return (free(data->philos), free(data->forks), 0);
	if (!init_forks(data))
		return (free(data->philos), free(data->forks), free(data->queue), 0);
	setup_philos(data);
	return (1);
}
