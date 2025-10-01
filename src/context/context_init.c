/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:04 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:17:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*context_destroy(t_context **context_ptr)
{
	t_context	*context;

	if (context_ptr == NULL || *context_ptr == NULL)
		return (NULL);
	context = *context_ptr;
	if (context->fork_head != NULL)
		fork_list_destroy(&context->fork_head);
	if (context->philos != NULL)
		free(context->philos);
	free(context);
	*context_ptr = NULL;
	return (NULL);
}

t_context	*context_init(int argc, char **argv)
{
	t_context	*context;
	t_param		param;

	param = parsing(argc, argv);
	context = malloc(sizeof(t_context));
	if (context == NULL)
		return (NULL);
	*context  = (t_context) {0};
	context->param = param;
	context->fork_head = fork_list_create(param.philo_max);
	if (context->fork_head == NULL)
		return (context_destroy(&context));
	philo_array_populate(context);
	context->state = PENDING;
	return (context);
}
