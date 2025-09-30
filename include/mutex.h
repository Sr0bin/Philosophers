/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:01:43 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 17:03:05 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H
# include "struct.h"

t_mutex_bool	mutex_bool_create(bool val);
void	*mutex_bool_destroy(t_mutex_bool mutex);
int	mutex_bool_access(t_mutex_bool mutex, int *error);
int	mutex_bool_unlock(t_mutex_bool mutex);
t_mutex_int	mutex_int_create(int val);
void	*mutex_int_destroy(t_mutex_int mutex);
int	mutex_int_access(t_mutex_int mutex, int *error);
int	mutex_int_unlock(t_mutex_int mutex);
#endif

