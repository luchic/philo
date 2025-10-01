/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:07:04 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/01 20:30:53 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

static int	allocate_data(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->count);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
		return (free(data->philos), 0);
	return (1);
}

int	init_data(t_data *data)
{
	if (!data)
		return (0);
	if (!allocate_data(data))
		return (0);
	if (!init_forks(data))
		return (free(data->philos), free(data->forks), 0);
	return (1);
}
