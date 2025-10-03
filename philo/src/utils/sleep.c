/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:14:23 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/02 14:06:06 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <unistd.h>

unsigned long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (unsigned long)(tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
}

// static unsigned long	get_end_time(t_philo *philo, unsigned long ms)
// {
// 	unsigned long	res;
// 	// unsigned long	common;
// 	unsigned long	cur;

// 	cur = now_ms();
// 	res = cur - philo->data->start_time;
// 	res += ms;
// 	res -= res % ms;

// 	return (res);
// }

void	sleep_ms(t_philo *philo, unsigned long ms)
{
	// unsigned long	end;
	unsigned long	cur;
	unsigned long	start;
	// unsigned long	rem;

	(void)philo;
	start = now_ms();
	cur = now_ms();
	while (cur - start < ms)
	{
		usleep(200);
		cur = now_ms();
	}
}
