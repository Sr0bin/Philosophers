/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:01:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 17:53:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

int		time_threshold(t_timeval time_to_pass, t_timeval time_to_check)
{
	
	if (time_to_pass.tv_sec == time_to_check.tv_sec)
	{
		if (time_to_pass.tv_usec <= time_to_check.tv_usec)
			return (1);
		return (0);
	}
	if (time_to_pass.tv_sec < time_to_check.tv_sec)
	{
			return (1);
	}
	return (0);
}

// Offset a t_timeval of the specified microseconds.
void	offset_time(t_timeval *input, long offset)
{
	const	long micro_per_sec = 1000000;
	input->tv_sec += offset / micro_per_sec;
	input->tv_usec += offset % micro_per_sec;
	if (input->tv_usec >= micro_per_sec)
	{
		input->tv_sec += input->tv_sec / micro_per_sec;
		input->tv_sec %= micro_per_sec;
	}

	
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
