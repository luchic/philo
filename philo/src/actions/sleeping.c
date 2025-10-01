/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:19:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/01 17:05:15 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <unistd.h>

void	sleeping(t_philo *philo)
{
	set_status(philo, SLEEPING);
	usleep(philo->data->time_to_sleep * 1000);
}
