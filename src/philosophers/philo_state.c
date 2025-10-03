/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:42:26 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 03:03:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eating(t_philo *philo)
{
	if (!philo_check_death(philo)
		&& check_run(philo)
		&& philo_check_ate(philo))
	{
		fork_pair_rest(&philo->pair, philo);
		philo_print_msg(philo, "is sleeping");
		gettimeofday(&philo->timer.s_start_time, NULL);
		philo->state = SLEEPING;
		add_meal(philo);
		granular_usleep((philo->context->param.time_const.time_to_sleep / 2) * USEC_PER_MSEC, philo);
	}
}

static void	philo_sleeping(t_philo *philo)
{
	if (!philo_check_death(philo)
		&& check_run(philo)
		&& philo_check_sleep(philo))
	{
		philo_print_msg(philo, "is thinking");
		gettimeofday(&philo->timer.s_start_time, NULL);
		philo->state = THINKING;
	}
}

static void	philo_thinking(t_philo *philo)
{
	while (!philo_check_death(philo) && check_run(philo))
	{
		usleep(1000);
		if (fork_pair_pickup(&philo->pair, philo) == true)
			break ;
	}
	if (philo_check_death(philo))
		return ;
	philo_print_msg(philo, "is eating");
	philo->state = EATING;
	gettimeofday(&philo->timer.last_meal, NULL);
	gettimeofday(&philo->timer.s_start_time, NULL);
	granular_usleep((philo->context->param.time_const.time_to_eat / 2) * USEC_PER_MSEC, philo);
}

t_philo	*philo_change_state(t_philo	*philo)
{
	if (philo->state == EATING)
		philo_eating(philo);
	else if (philo->state == SLEEPING)
		philo_sleeping(philo);
	else if (philo->state == THINKING)
		philo_thinking(philo);
	return (philo);
}
