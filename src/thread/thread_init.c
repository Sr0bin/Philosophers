/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:44:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 18:02:53 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*start_routine(void	*philo_struct)
{
	t_philo	philo_crnt;
	t_timeval	start_time;
	t_timeval	crnt_time;

	philo_crnt = *(t_philo *) philo_struct;
	start_time = philo_crnt.context->param.time_const.sim_start;
	gettimeofday(&crnt_time, NULL);
	while (!time_threshold(start_time, crnt_time))
	{
		usleep(100);
		gettimeofday(&crnt_time, NULL);
	}
	print_philo(&philo_crnt);
	return (NULL);
}

void	*thread_destroy_philo(t_context *context)
{
	size_t i;
	t_philo	*philo_crnt;

	i = 0;
	philo_crnt = context->philos;
	while (i < context->param.philo_max)
	{

		pthread_join(philo_crnt->thread_id, NULL);
		philo_crnt++;
		i++;
	}
	return (NULL);
}
int	thread_creation_loop(t_context *context)
{
	size_t	i;
	t_philo	*philo_crnt;

	i = 0;
	philo_crnt = context->philos;
	while (i < context->param.philo_max)
	{
		pthread_create(&philo_crnt->thread_id, NULL, &start_routine, philo_crnt);
		philo_crnt++;
		i++;
	}
	return (0);
}
