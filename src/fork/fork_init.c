/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:54:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 17:02:55 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*fork_create(int index, t_fork *previous, t_fork *next)
{
	t_fork	*fork;
	t_mutex_bool	state;

	state = mutex_bool_create(0);
	if (state == NULL)
		return (NULL);
	fork = malloc(sizeof(t_fork));
	if (fork == NULL)
	{
		mutex_bool_destroy(state);
	}

}
