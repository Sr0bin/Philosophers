/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   granular_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:23:01 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 20:12:27 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	granular_usleep(long usec, t_philo *philo)
{
	gettimeofday(&philo->timer.w_start_time, NULL);
	while (1)
	{
		gettimeofday(&philo->timer.w_crnt_time, NULL);
		if (time_difference(philo->timer.w_start_time, philo->timer.w_crnt_time) > usec)
			break;
		usleep(SLEEP_DELTA);
	}
}
