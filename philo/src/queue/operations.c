/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:56:09 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 10:08:25 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <string.h>

void	ent_queue(t_queue *q, t_event value)
{
	if (is_full(q))
		return ;
	q->arr[q->front] = value;
	q->front = (q->front + 1) % MAX_SIZE;
	q->count++;
}

void	det_queue(t_queue *q)
{
	if (is_empty(q))
		return ;
	q->count--;
}

t_event	peek(t_queue *q)
{
	t_event	empty;

	if (is_empty(q))
	{
		memset(&empty, 0, sizeof(t_event));
		empty.type = IS_EMPTY;
		return (empty);
	}
	return (q->arr[head_index(q)]);
}
