/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:42:26 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 20:08:32 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_check_death(t_philo *philo)
{
	gettimeofday(&philo->timer.s_crnt_time, NULL);
	if (time_difference(philo->timer.last_meal, philo->timer.s_crnt_time)
	>= philo->context->param.time_const.time_to_die * USEC_PER_MSEC)
	{
		sim_end(philo);
		return (true);
	}
	return (false);
}

bool	philo_check_ate(t_philo *philo)
{
	gettimeofday(&philo->timer.s_crnt_time, NULL);
	if (time_difference(philo->timer.s_start_time, philo->timer.s_crnt_time)
	>= philo->context->param.time_const.time_to_eat * USEC_PER_MSEC)
		return (true);
	return (false);
}

bool	philo_check_sleep(t_philo *philo)
{
	gettimeofday(&philo->timer.s_crnt_time, NULL);
	if (time_difference(philo->timer.s_start_time, philo->timer.s_crnt_time)
	>= philo->context->param.time_const.time_to_sleep * USEC_PER_MSEC)
		return (true);
	return (false);
}

t_philo	*philo_change_state(t_philo	*philo)
{
	if (philo->state == EATING)
	{
		philo_check_death(philo);
		if (philo_check_ate(philo) && check_run(philo))
		{
			fork_pair_rest(&philo->pair, philo);
			philo_print_msg(philo, "is sleeping");
			gettimeofday(&philo->timer.s_start_time, NULL);
			philo->state = SLEEPING;
			add_meal(philo);
		}
	}
	else if (philo->state == SLEEPING)
	{
		philo_check_death(philo);
		if (philo_check_sleep(philo) && check_run(philo))
		{
			philo->state = THINKING;
			philo_print_msg(philo, "is thinking");
			gettimeofday(&philo->timer.s_start_time, NULL);
		}
	}
	else if (philo->state == THINKING)
	{
		while (!philo_check_death(philo)) 
		{
			usleep(1000);
			if (fork_pair_pickup(&philo->pair, philo) == true)
				break ;
		}
		if (philo_check_death(philo))
			return (philo);
		philo->state = EATING;
		philo_print_msg(philo, "is eating");
		gettimeofday(&philo->timer.last_meal, NULL);
		gettimeofday(&philo->timer.s_start_time, NULL);
	}
	return (philo);
}
