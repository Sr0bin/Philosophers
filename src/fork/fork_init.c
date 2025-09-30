/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:54:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 17:16:07 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*fork_create(int index, t_fork *previous, t_fork *next)
{
	int	error;
	t_fork	*fork;
	t_mutex_bool	state;

	state = mutex_bool_create(0, &error);
	if (error != 0)
		return (NULL);
	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
	{
		mutex_bool_destroy(state);
		return (NULL);
	}
	*fork = (t_fork) {0};
	fork->index = index;
	fork->state = state;
	fork->next = next;
	fork->previous = previous;
	return (fork);
}

t_fork	*fork_destroy(t_fork **fork)
{
	t_mutex_bool	*ret;

	ret = mutex_bool_destroy((*fork)->state);
	if (ret == &(*fork)->state)
		return (*fork);

	(**fork) = (t_fork) {0};
	free(*fork);
	*fork = NULL;
	return (NULL);
}
