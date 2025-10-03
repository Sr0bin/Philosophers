/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:42:51 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 07:08:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_run(t_philo *philo)
{
	if (mutex_bool_access(&philo->context->running, &philo->ret) == true)
	{
		mutex_bool_unlock(&philo->context->running);
		if (mutex_int_access(&philo->context->philo_meal_max, &philo->ret)
			== philo->context->param.philo_max)
		{
			mutex_int_unlock(&philo->context->philo_meal_max);
			return (false);
		}
		mutex_int_unlock(&philo->context->philo_meal_max);
		return (true);
	}
	mutex_bool_unlock(&philo->context->running);
	return (false);
}

void	add_meal(t_philo *philo)
{
	if (++(philo->meal) == philo->context->param.max_meal)
	{
		mutex_int_access(&philo->context->philo_meal_max, &philo->ret);
		philo->context->philo_meal_max.val++;
		mutex_int_unlock(&philo->context->philo_meal_max);
	}
}

void	sim_end(t_philo	*philo)
{
	philo->state = DEAD;
	philo_print_death(philo, "died");
}
