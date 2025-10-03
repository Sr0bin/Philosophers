/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:07:46 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 07:08:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_msg(t_philo	*philo, const char *msg)
{
	mutex_bool_access(&philo->context->running, &philo->ret);
	mutex_bool_access(&philo->context->write_mutex, &philo->ret);
	if (philo->context->running.val == true)
		printf("%ld %zu %s\n", sim_time(philo->context), philo->index, msg);
	mutex_bool_unlock(&philo->context->running);
	mutex_bool_unlock(&philo->context->write_mutex);
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
