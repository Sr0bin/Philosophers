/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:48:07 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 19:50:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_pair_unlock(t_fork_pair *pair, t_philo *philo)
{
	mutex_bool_access(&pair->right->state, &philo->ret);
	pair->right->state.val = 0;
	mutex_bool_access(&pair->left->state, &philo->ret);
	pair->left->state.val = 0;
}

void	fork_pair_lock(t_fork_pair *pair, t_philo *philo)
{
	mutex_bool_access(&pair->left->state, &philo->ret);
	pair->left->state.val = 1;
	mutex_bool_access(&pair->right->state, &philo->ret);
	pair->right->state.val = 1;
}

t_fork_pair	fork_pair_gen(t_fork *head, size_t index)
{
	t_fork_pair	ret;
	size_t		i;

	i = 0;
	while (i < index)
	{
		head = head->next;
		i++;
	}
	if (index % 2)
	{
		ret.left = head;
		ret.right = head->next;
	}
	else
	{
		ret.right = head;
		ret.left = head->next;
	}
	return (ret);
}
