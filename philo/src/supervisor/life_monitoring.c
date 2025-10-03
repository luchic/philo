/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:43:26 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 14:21:56 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdlib.h>
#include <string.h>

int	init_life_times(t_data *data, t_life_time **life_times)
{
	int	i;

	*life_times = malloc(sizeof(t_life_time) * data->count);
	if (!*life_times)
		return (0);
	i = -1;
	while (++i < data->count)
	{
		(*life_times)[i].id = data->philos[i].id;
		(*life_times)[i].last_meal = data->start_time;
	}
	return (1);
}

void	update_meal_time(t_life_time *life_times, int philo_id,
		unsigned long time)
{
	life_times[philo_id].last_meal = time;
}

int	update_dead_status_if_dead(t_data *data, t_life_time *life_times)
{
	int				i;
	int				is_dead;
	unsigned long	current_time;

	i = -1;
	current_time = now_ms();
	is_dead = 0;
	while (++i < data->count)
	{
		if (life_times[i].id == -1)
			continue ;
		if ((int)(current_time - life_times[i].last_meal) > data->time_to_die)
		{
			is_dead = 1;
			break ;
		}
	}
	if (is_dead)
		set_death(data, is_dead);
	return (is_dead);
}
