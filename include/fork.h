/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:41 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 07:13:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H
# include "struct.h"

t_fork		*fork_create(int index);
t_fork		*fork_list_create(size_t number);
t_fork		*fork_destroy(t_fork **fork);
t_fork		*fork_list_destroy(t_fork **fork);

t_fork_pair	fork_pair_gen(t_fork *head, size_t index);
bool		fork_pair_pickup(t_fork_pair *pair, t_philo *philo);
int			fork_pair_rest(t_fork_pair *pair, t_philo *philo);
#endif
