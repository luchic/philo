/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:55:29 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/04 14:42:10 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>
# include <sys/time.h>

# define MAX_SIZE 1024
# define SLEEP_INTERVAL 200

typedef struct s_data	t_data;
typedef struct s_queue	t_queue;

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING
}						t_state;

typedef enum e_event_type
{
	IS_EMPTY,
	FORK_TAKEN,
	PHILO_EATING,
	PHILO_SLEEPING,
	PHILO_THINKING,
	END_ITER
}						t_event_type;

typedef struct s_philo
{
	int					id;
	int					iterations;
	pthread_t			pid;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;

}						t_philo;

typedef struct s_data
{
	int					count;
	int					is_dead;
	int					max_iter;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	t_queue				*queue;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		is_dead_lock;
	unsigned long		start_time;
}						t_data;

typedef struct s_event
{
	int					philo_id;
	t_state				state;
	unsigned long		timestamp;
	t_event_type		type;
}						t_event;

typedef struct s_life_time
{
	int					id;
	unsigned long		last_meal;
}						t_life_time;

typedef struct s_queue
{
	t_event				arr[MAX_SIZE];
	pthread_mutex_t		lock;
	int					count;
	int					front;
}						t_queue;

#endif