/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 23:43:14 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 23:43:24 by rorollin         ###   ########.fr       */
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

