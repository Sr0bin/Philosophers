/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:48:07 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 22:59:19 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_pair_rest(t_fork_pair *pair, t_philo *philo)
{
	mutex_bool_access(&pair->left->state, &philo->ret);
	if (pair->left->state.val == true)
		pair->left->state.val = false;
	mutex_bool_unlock(&pair->left->state);
	mutex_bool_access(&pair->right->state, &philo->ret);
	if (pair->right->state.val == true)
		pair->right->state.val = false;
	mutex_bool_unlock(&pair->right->state);
	return (0);
}

bool	fork_pair_pickup(t_fork_pair *pair, t_philo *philo)
{
	mutex_bool_access(&pair->left->state, &philo->ret);
	if (pair->left->state.val == false && philo->ret == 0)
	{
		pair->left->state.val = true;
		mutex_bool_unlock(&pair->left->state);
		philo_print_msg(philo, "has taken a fork");
	}
	else
	{
		mutex_bool_unlock(&pair->left->state);
		// philo_print_msg(philo, "can't take left fork");
		return (false);
	}
	mutex_bool_access(&pair->right->state, &philo->ret);
	while (!philo_check_death(philo)
		&& pair->right->state.val == true
		&& philo->ret == 0
		&& check_run(philo))
	{
		mutex_bool_unlock(&pair->right->state);
		usleep(1000);
		mutex_bool_access(&pair->right->state, &philo->ret);
	}
	pair->right->state.val = true;
	mutex_bool_unlock(&pair->right->state);
	philo_print_msg(philo, "has taken a fork");
	return (true);
}

// bool	fork_pair_pickup(t_fork_pair *pair, t_philo *philo)
// {
// 	mutex_bool_access(&pair->left->state, &philo->ret);
// 	if (pair->left->state.val == false && philo->ret == 0)
// 		pair->left->state.val = true;
// 	else
// 	{
// 		mutex_bool_unlock(&pair->left->state);
// 		return (false);
// 	}
// 	mutex_bool_access(&pair->right->state, &philo->ret);
// 	if (pair->right->state.val == false && philo->ret == 0)
// 	{
// 		pair->right->state.val = true;
// 		mutex_bool_unlock(&pair->right->state);
// 		philo_print_msg(philo, "has taken a fork");
// 		return (true);
// 	}
// 	mutex_bool_unlock(&pair->right->state);
// 	pair->left->state.val = false;
// 	mutex_bool_unlock(&pair->left->state);
// 	return (false);
// }
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
