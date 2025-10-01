/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:01:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:01:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

// Offset a t_timeval of the specified microseconds.
void	offset_time(t_timeval *input, long offset)
{
	const	long exponent = 1000000;
	input->tv_sec += offset / exponent;
	input->tv_usec += offset % exponent;
}

t_time_const	time_init(t_input input)
{
	t_timeval	crnt_time;
	t_time_const timers;

	timers.time_to_eat = input.time_to_eat;
	timers.time_to_die = input.time_to_die;
	timers.time_to_sleep = input.time_to_sleep;
	gettimeofday(&crnt_time, NULL);
	offset_time(&crnt_time, START_OFFSET);
	timers.sim_start = crnt_time;
	return (timers);
}
