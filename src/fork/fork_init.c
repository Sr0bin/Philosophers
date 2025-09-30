/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:54:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 20:44:55 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*fork_create(int index)
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
	return (fork);
}

t_fork	*fork_list_create(int number)
{
	int	i;
	t_fork	*fork_head;
	t_fork	*fork_crnt;
	t_fork	*fork_next;

	i = 1;
	fork_head = fork_create(0);
	if (fork_head == NULL)
		return (NULL);
	fork_crnt = fork_head;
	while (i < number)
	{
		fork_next = fork_create(i);
		if (fork_next == NULL)
			return (fork_list_destroy(&fork_head));
		fork_crnt->next = fork_next;
		fork_crnt = fork_next;
		i++;
	}
	fork_crnt->next = fork_head;
	return (fork_head);
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

t_fork	*fork_list_destroy(t_fork **fork)
{
	t_fork	*fork_start;
	t_fork	*fork_crnt;
	t_fork	*fork_next;

	fork_crnt = *fork;
	fork_start = fork_crnt;
	while (fork_crnt != NULL)
	{
		fork_next = fork_crnt->next;
		if (fork_destroy(&fork_crnt) != NULL)
			return (fork_crnt);
		fork_crnt = fork_next;
		if (fork_crnt == fork_start)
			break ;
	}
	return (NULL);
}
