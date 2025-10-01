/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:05:41 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/01 20:37:13 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

void	setup_philos(t_data *data)
{
	int	i;

	if (!data || data->count <= 0)
		return ;
	i = -1;
	while (++i < data->count)
	{
		data->philos[i].id = i;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->count];
	}
}
