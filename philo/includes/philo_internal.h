/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:54:03 by nluchini          #+#    #+#             */
/*   Updated: 2025/10/07 19:26:40 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INTERNAL_H
# define PHILO_INTERNAL_H

# include "defines.h"

void			set_status(t_philo *philo, t_state state);

// ============= Actions =============
int				eating(t_philo *philo);
int				sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			run_action(void *arg);

// ============= Init =============
int				parse_data(int count, char **values, t_data *data);
int				init_forks(t_data *data);
void			setup_philos(t_data *data);
int				init_data(t_data *data);

// ============= Supervisor =============
int				run_supervisor(void *arg);
int				init_life_times(t_data *data, t_life_time **life_times);
int				init_life_times(t_data *data, t_life_time **life_times);
void			update_meal_time(t_life_time *life_times, int philo_id,
					unsigned long time);
int				update_dead_status_if_dead(t_data *data,
					t_life_time *life_times);

// ============= Utils =============
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_issign(char c);
int				ft_atoi(const char *str);
int				validate_args(char **argv, int argc);
int				sleep_ms(t_philo *philo, unsigned long ms);
unsigned long	get_delta_ms(t_data *data);
unsigned long	now_ms(void);
void			set_death(t_data *data, int is_dead);
int				get_dead_status(t_data *data);

// ============= Queue =============
int				is_empty(t_queue *q);
int				init_queue(t_data *data);
int				is_full(t_queue *q);
int				head_index(t_queue *q);
void			ent_queue(t_queue *q, t_event value);
void			det_queue(t_queue *q);
t_event			peek(t_queue *q);

// ============= Events =============
int				get_event(t_data *data, t_event *events, int max_size);
void			send_event(t_data *data, t_event event);
void			set_iter_end(t_data *data, int status);

#endif