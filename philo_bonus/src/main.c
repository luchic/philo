/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:22:52 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/03 19:41:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	cleanup(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (++i < data->count)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->is_dead_lock);
	pthread_mutex_destroy(&data->queue->lock);
	free(data->philos);
	free(data->forks);
	free(data->queue);
}

static int	start_simulation(t_data *data)
{
	int				i;
	pthread_t		supervisor;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	data->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	i = -1;
	while (++i < data->count)
	{
		if (pthread_create(&data->philos[i].pid, NULL, (void *)run_action,
				(void *)&data->philos[i]) != 0)
			return (1);
	}
	if (pthread_create(&supervisor, NULL, (void *)run_supervisor,
			(void *)data) != 0)
		return (1);
	i = -1;
	while (++i < data->count)
		pthread_join(data->philos[i].pid, NULL);
	pthread_join(supervisor, NULL);
	return (1);
}

static int	run(t_data *data, int count, char **args)
{
	if (!validate_args(args, count))
		return (printf("Error: Invalid arguments\n"), 0);
	if (!parse_data(count, args, data))
		return (printf("Error: Failed to parse arguments\n"), 0);
	if (!init_data(data))
		return (printf("Error: Failed to initialize philosophers\n"), 0);
	start_simulation(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc != 5 && argc != 6)
		return (printf("Error: Invalid number of arguments\n"), 1);
	run(&data, argc - 1, argv + 1);
	cleanup(&data);
	printf("Simulation ended\n");
	return (0);
}
