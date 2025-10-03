/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 06:54:21 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 06:54:36 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H
# include "struct.h" 

void			granular_usleep(long usec, t_philo *philo);
t_time_const	time_init(t_input input);
int				time_threshold(t_timeval time_to_pass, t_timeval time_to_check);
long			sim_time(t_context	*context);
void			offset_time(t_timeval *input, long offset);
long			time_difference(t_timeval a, t_timeval b);
#endif
