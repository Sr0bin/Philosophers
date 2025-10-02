/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:44:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 23:44:43 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"
#include "philo.h"
#include "struct.h"
#include "timer.h"
#include <pthread.h>

void	philo_print_msg(t_philo	*philo, const char* msg)
{
	mutex_bool_access(&philo->context->running, &philo->ret);
	mutex_bool_access(&philo->context->write_mutex, &philo->ret);
	if (philo->context->running.val == true)
		printf("%ld %zu %s\n", sim_time(philo->context), philo->index, msg);
	mutex_bool_unlock(&philo->context->write_mutex);
	mutex_bool_unlock(&philo->context->running);
}

void	philo_loop(t_philo	*philo)
{
	philo_print_msg(philo, "is thinking");
	if (philo->index % 2)
		granular_usleep((philo->context->param.time_const.time_to_eat / 2) * USEC_PER_MSEC, philo);
	while (!philo_check_death(philo) && check_run(philo) == true)
	{
		philo_change_state(philo);
		usleep(1000);
	}
}

void	*start_routine(void	*philo_struct)
{
	t_philo		philo_crnt;
	t_timeval	start_time;
	t_timeval	crnt_time;

	philo_crnt = *(t_philo *) philo_struct;
	start_time = philo_crnt.context->sim_time.sim_start;
	gettimeofday(&crnt_time, NULL);
	while (!time_threshold(start_time, crnt_time))
	{
		usleep(1000);
		gettimeofday(&crnt_time, NULL);
	}
	philo_loop(&philo_crnt);
	// print_philo(&philo_crnt);
	return (NULL);
}
