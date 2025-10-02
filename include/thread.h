/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:39:59 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 23:44:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "struct.h"

void	*start_routine(void	*philo_struct);
int	thread_creation_loop(t_context *context);
void	*thread_destroy_philo(t_context *context);
int	check_run(t_philo *philo);
void	sim_end(t_philo	*philo);
bool	philo_check_death(t_philo *philo);
bool	philo_check_ate(t_philo *philo);
bool	philo_check_sleep(t_philo *philo);
void	philo_print_msg(t_philo	*philo, const char* msg);
t_philo	*philo_change_state(t_philo	*philo);
#endif

