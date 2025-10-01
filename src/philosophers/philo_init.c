/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:45:54 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:17:49 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"
#include "philo.h"

t_philo	philo_struct_create(size_t index, t_context *context)
{
	t_philo	philo;

	philo = (t_philo) {0};
	philo.index = index;
	philo.state = THINKING;
	philo.pair = fork_pair_gen(context->fork_head, index);
	return (philo);
}

t_philo	*philo_array_populate(t_context	*context)
{
	size_t	i;
	t_philo	*philo_crnt;

	i = 0;
	context->philos = malloc(context->param.philo_max * sizeof(t_philo));
	if (context->philos == NULL)
		return (context_destroy(&context));
	philo_crnt = context->philos;
	while (i < context->param.philo_max)
	{
		*philo_crnt = philo_struct_create(i, context);
		philo_crnt++;
		i++;
	}
	return (context->philos);
	
}
