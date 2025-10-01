/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:56:40 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:20:21 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>

int	mutex_int_unlock(t_mutex_int mutex)
{
	return (pthread_mutex_unlock(&mutex.mutex));
}

int	mutex_int_access(t_mutex_int mutex, int *error)
{
	*error = pthread_mutex_lock(&mutex.mutex);
	if (*error != 0)
		return (0);
	return (mutex.val);
}

void	*mutex_int_destroy(t_mutex_int mutex)
{
	int	ret;

	ret = pthread_mutex_destroy(&mutex.mutex);
	if (ret != 0)
		return (NULL);
	return (&mutex);
}

t_mutex_int	mutex_int_create(int val, int *error)
{
	t_mutex_int			mutex;
	pthread_mutex_t	pmutex;

	*error = pthread_mutex_init(&pmutex, NULL);
	mutex.mutex = pmutex;
	mutex.val = val;
	return (mutex);
}
