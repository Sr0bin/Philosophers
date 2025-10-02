/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:01:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 15:25:39 by rorollin         ###   ########.fr       */
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

long	time_difference(t_timeval a, t_timeval b)
{
	return (((b.tv_sec - a.tv_sec) * USEC_PER_SEC) + (b.tv_usec - a.tv_usec));
}

long	sim_time(t_context	*context)
{
	gettimeofday(&context->sim_time.sim_crnt, NULL);
	return (time_difference(context->sim_time.sim_start, context->sim_time.sim_crnt)
	/ USEC_PER_MSEC);
}

// Offset a t_timeval of the specified microseconds.
void	offset_time(t_timeval *input, long offset)
{
	input->tv_sec += offset / USEC_PER_SEC;
	input->tv_usec += offset % USEC_PER_SEC;
	if (input->tv_usec >= USEC_PER_SEC)
	{
		input->tv_sec += input->tv_usec / USEC_PER_SEC;
		input->tv_usec %= USEC_PER_SEC;
	}
}

t_time_const	time_init(t_input input)
{
	t_timeval	crnt_time;
	t_time_const timers;

	timers.time_to_eat = input.time_to_eat;
	timers.time_to_die = input.time_to_die;
	timers.time_to_sleep = input.time_to_sleep;
	return (timers);
}
