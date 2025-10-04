/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:14:23 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/04 14:48:40 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <unistd.h>

unsigned long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long)(tv.tv_sec * 1000UL + tv.tv_usec / 1000UL));
}

unsigned long	get_delta_ms(t_data *data)
{
	unsigned long	end;

	end = now_ms() - data->start_time;
	return (end);
}

static unsigned long	get_deadline_ms(t_philo *philo, unsigned long ms)
{
	int	allignment;
	int	ms_unit;
	int	cur_unit;

	ms_unit = ms / 10;
	cur_unit = get_delta_ms(philo->data) / 10;
	if (ms == 0)
		allignment = cur_unit % 10;
	else
		allignment = cur_unit % ms_unit;
	return (get_delta_ms(philo->data) + ms - allignment);
}

int	sleep_ms(t_philo *philo, unsigned long ms)
{
	int				counter;
	unsigned long	deadline;

	deadline = get_deadline_ms(philo, ms);
	counter = -1;
	while (get_delta_ms(philo->data) < deadline)
	{
		counter = (counter + 1) % 5;
		if (counter == 4)
		{
			if (get_dead_status(philo->data))
				return (1);
		}
		usleep(SLEEP_INTERVAL);
	}
	return (0);
}
