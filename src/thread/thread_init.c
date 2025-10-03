/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:44:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 07:08:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"
#include "philo.h"
#include "struct.h"
#include "timer.h"
#include <pthread.h>

void	philo_loop(t_philo	*philo)
{
	philo_print_msg(philo, "is thinking");
	if (philo->index % 2)
		granular_usleep((philo->context->param.time_const.time_to_eat / 2)
			* USEC_PER_MSEC, philo);
	while (!philo_check_death(philo) && check_run(philo) == true)
	{
		if (philo->state == EATING)
			philo_eating(philo);
		else if (philo->state == SLEEPING)
			philo_sleeping(philo);
		else if (philo->state == THINKING)
			philo_thinking(philo);
		usleep(500);
	}
}

void	*start_routine(void	*philo_struct)
{
	t_philo		philo_crnt;
	t_timeval	start_time;
	t_timeval	crnt_time;

	philo_crnt = *(t_philo *) philo_struct;
	start_time = philo_crnt.context->sim_t.sim_start;
	gettimeofday(&crnt_time, NULL);
	while (!time_threshold(start_time, crnt_time))
	{
		usleep(1000);
		gettimeofday(&crnt_time, NULL);
	}
	philo_loop(&philo_crnt);
	return (NULL);
}
