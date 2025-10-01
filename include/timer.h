/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:17:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 19:39:08 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H
# include "struct.h" 

void	granular_usleep(long usec, t_philo *philo);
t_time_const	time_init(t_input input);
int		time_threshold(t_timeval time_to_pass, t_timeval time_to_check);
long	time_difference(t_timeval a, t_timeval b);
#endif

