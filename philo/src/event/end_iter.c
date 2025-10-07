/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:25:15 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/07 19:26:24 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

void	set_iter_end(t_data *data, int status)
{
	pthread_mutex_lock(&data->is_dead_lock);
	data->is_phinished = status;
	pthread_mutex_unlock(&data->is_dead_lock);
}
