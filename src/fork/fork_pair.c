/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:48:07 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 20:50:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork_pair	fork_pair_gen(t_fork *head, int index)
{
	t_fork_pair	ret;
	int			i;

	i = 0;
	while (i < index)
	{
		head = head->next;
		i++;
	}
	ret.left = head;
	ret.right = head->next;
	return (ret);
}
