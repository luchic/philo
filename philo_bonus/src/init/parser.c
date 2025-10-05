/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:12:54 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/02 12:40:45 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"

int	parse_data(int count, char **values, t_data *data)
{
	if (!data)
		return (0);
	data->count = ft_atoi(values[0]);
	data->time_to_die = ft_atoi(values[1]);
	data->time_to_eat = ft_atoi(values[2]);
	data->time_to_sleep = ft_atoi(values[3]);
	if (count == 5)
		data->max_iter = ft_atoi(values[4]);
	else
		data->max_iter = -1;
	return (1);
}
