/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:42:51 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 23:52:24 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_run(t_philo *philo)
{
	if (mutex_bool_access(&philo->context->running, &philo->ret) == true)
	{
		//todo check ret
		// if (mutex_int_access(&philo->context->philo_meal_max, &philo->ret)
		// == philo->context->param.max_meal)
		// {
		// 	mutex_int_unlock(&philo->context->philo_meal_max);
		// 	mutex_bool_unlock(&philo->context->running);
		// 	return (false);
		// }
		mutex_bool_unlock(&philo->context->running);
		return (true);
	}
	mutex_bool_unlock(&philo->context->running);
	return (false);
}

void	add_meal(t_philo *philo)
{
	if ((++philo->meal) == philo->context->param.max_meal)
	{
		mutex_int_access(&philo->context->philo_meal_max, &philo->ret);
		philo->context->philo_meal_max.val++;
		mutex_int_unlock(&philo->context->philo_meal_max);
	}
}

void	philo_print_death(t_philo	*philo, const char *msg)
{
	mutex_bool_access(&philo->context->running, &philo->ret);
	mutex_bool_access(&philo->context->write_mutex, &philo->ret);
	if (philo->context->running.val == true)
	{
		printf("%ld %zu %s\n", sim_time(philo->context), philo->index, msg);
		philo->context->running.val = false;
	}
	mutex_bool_unlock(&philo->context->running);
	mutex_bool_unlock(&philo->context->write_mutex);
}

void	sim_end(t_philo	*philo)
{
	philo->state = DEAD;
	philo_print_death(philo, "died");
}
