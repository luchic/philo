/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:07:39 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 10:07:48 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int	is_empty(t_queue *q)
{
	return (q->count == 0);
}

int	is_full(t_queue *q)
{
	return (q->count == MAX_SIZE);
}

int	head_index(t_queue *q)
{
	return ((q->front - q->count + MAX_SIZE) % MAX_SIZE);
}
