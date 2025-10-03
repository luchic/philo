/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qinit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:53:08 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 10:06:50 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include <stdlib.h>
#include <string.h>

int	init_queue(t_data *data)
{
	data->queue = NULL;
	data->queue = malloc(sizeof(t_queue));
	if (!data->queue)
		return (0);
	memset(data->queue, 0, sizeof(t_queue));
	return (1);
}
