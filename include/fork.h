/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:41 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 20:31:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H
# include "struct.h"

t_fork	*fork_create(int index);
t_fork	*fork_list_create(int number);
t_fork	*fork_destroy(t_fork **fork);
t_fork	*fork_list_destroy(t_fork **fork);
#endif

