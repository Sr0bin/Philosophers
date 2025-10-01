/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:44:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:39:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void	*philo_struct)
{
	t_philo	philo_crnt;

	philo_crnt = *(t_philo *) philo_struct;
	print_philo(&philo_crnt);
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
