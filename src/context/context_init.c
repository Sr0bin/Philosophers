/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:04 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 07:03:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "mutex.h"
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

void	*context_create_mutex(t_context	*context)
{
	int	ret;

	mutex_bool_create(0, &context->write_mutex.mutex, &ret);
	if (ret != 0)
		return (NULL);
	mutex_bool_create(0, &context->running.mutex, &ret);
	if (ret != 0)
	{
		mutex_bool_destroy(&context->write_mutex);
		return (NULL);
	}
	context->running.val = true;
	mutex_int_create(context->param.max_meal,
		&context->philo_meal_max.mutex, &ret);
	if (ret != 0)
	{
		mutex_bool_destroy(&context->running);
		mutex_bool_destroy(&context->write_mutex);
		return (NULL);
	}
	return (context);
}

t_context	*context_init(int argc, char **argv)
{
	t_context	*context;
	t_param		param;
	int			ret;

	param = parsing(argc, argv, &ret);
	if (ret == 1)
		return (NULL);
	context = malloc(sizeof(t_context));
	if (context == NULL)
		return (NULL);
	*context = (t_context){0};
	context->param = param;
	context->fork_head = fork_list_create(param.philo_max);
	if (context->fork_head == NULL)
		return (context_destroy(&context));
	gettimeofday(&context->sim_t.sim_start, NULL);
	offset_time(&context->sim_t.sim_start, START_OFFSET);
	context_create_mutex(context);
	if (philo_array_populate(context) == NULL)
		return (NULL);
	return (context);
}
