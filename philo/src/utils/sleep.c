/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:14:23 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 19:41:01 by nluchini         ###   ########.fr       */
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

int	sleep_ms(t_philo *philo, unsigned long ms)
{
	int				counter;
	unsigned long	cur;
	unsigned long	start;

	(void)philo;
	start = now_ms();
	cur = now_ms();
	counter = -1;
	while (cur - start < ms)
	{
		counter = (counter + 1) % 5;
		if (counter == 4)
		{
			if (get_dead_status(philo->data))
				return (1);
		}
		usleep(SLEEP_INTERVAL);
		cur = now_ms();
	}
	return (0);
}
