/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:17:50 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 11:24:35 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

void	set_death(t_data *data, int is_dead)
{
	pthread_mutex_lock(&data->is_dead_lock);
	data->is_dead = is_dead;
	pthread_mutex_unlock(&data->is_dead_lock);
}

int	get_dead_status(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->is_dead_lock);
	res = data->is_dead;
	pthread_mutex_unlock(&data->is_dead_lock);
	return (res);
}
