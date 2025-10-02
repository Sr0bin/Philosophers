/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:04 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 20:18:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*context_destroy(t_context **context_ptr)
{
	t_context	*context;

	if (context_ptr == NULL || *context_ptr == NULL)
		return (NULL);
	context = *context_ptr;
	if (context->philos != NULL)
	{
		thread_destroy_philo(context);
		free(context->philos);
	}
	if (context->fork_head != NULL)
		fork_list_destroy(&context->fork_head);
	mutex_bool_destroy(&context->write_mutex);
	mutex_int_destroy(&context->philo_meal_max);
	free(context);
	*context_ptr = NULL;
	return (NULL);
}

t_context	*context_init(int argc, char **argv)
{
	t_context	*context;
	t_param		param;
	int	ret;

	param = parsing(argc, argv);
	context = malloc(sizeof(t_context));
	if (context == NULL)
		return (NULL);
	*context  = (t_context) {0};
	context->param = param;
	context->fork_head = fork_list_create(param.philo_max);
	if (context->fork_head == NULL)
		return (context_destroy(&context));
	gettimeofday(&context->sim_time.sim_start, NULL);
	offset_time(&context->sim_time.sim_start, START_OFFSET);
	philo_array_populate(context);
	context->state = PENDING;
	context->write_mutex = mutex_bool_create(0, &ret);
	context->running = mutex_bool_create(0, &ret);
	context->philo_meal_max = mutex_int_create(param.max_meal, &ret);
	context->running.val = true;
	return (context);
}
