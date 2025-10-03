/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:19:43 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 11:31:21 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <unistd.h>

int	sleeping(t_philo *philo)
{
	set_status(philo, SLEEPING);
	return (sleep_ms(philo, philo->data->time_to_sleep));
}
