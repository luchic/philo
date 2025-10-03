/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:19:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/02 13:52:18 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <unistd.h>

void	sleeping(t_philo *philo)
{
	set_status(philo, SLEEPING);
	sleep_ms(philo, philo->data->time_to_sleep);
}
