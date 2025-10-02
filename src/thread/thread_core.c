/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 23:44:14 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 23:44:44 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_destroy_philo(t_context *context)
{
	size_t		i;
	t_philo		*philo_crnt;

	i = 0;
	philo_crnt = context->philos;
	while (i < context->param.philo_max)
	{
		pthread_join(philo_crnt->th_id, NULL);
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
		pthread_create(&philo_crnt->th_id, NULL, &start_routine, philo_crnt);
		philo_crnt++;
		i++;
	}
	return (0);
}
