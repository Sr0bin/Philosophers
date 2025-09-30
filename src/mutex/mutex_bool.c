/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:51:11 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 17:06:09 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_bool_unlock(t_mutex_bool mutex)
{
	return (pthread_mutex_unlock(&mutex.mutex));
}

int	mutex_bool_access(t_mutex_bool mutex, int *error)
{
	*error = pthread_mutex_lock(&mutex.mutex);
	if (*error != 0)
		return (0);
	return (mutex.val);
}

void	*mutex_bool_destroy(t_mutex_bool mutex)
{
	int	ret;

	ret = pthread_mutex_destroy(&mutex.mutex);
	if (ret != 0)
		return (NULL);
	return (&mutex);
}

t_mutex_bool	mutex_bool_create(bool val, int *error)
{
	t_mutex_bool			mutex;
	pthread_mutex_t	pmutex;

	*error = pthread_mutex_init(&pmutex, NULL);
	mutex.mutex = pmutex;
	mutex.val = val;
	return (mutex);
}
