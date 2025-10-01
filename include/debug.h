/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:33:40 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:07:46 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "struct.h"
// Basic struct print functions
void		print_mutex_int(const char *name, t_mutex_int *mi);
void		print_mutex_bool(const char *name, t_mutex_bool *mb);
void		print_fork(t_fork *fork);
void		print_fork_pair(const char *name, t_fork_pair *pair);
void		print_time_const(t_time_const *tc);
void		print_input(t_input *input);
void		print_param(t_param *param);
void		print_philo(t_philo *philo);

// Aggregate print functions
void		print_all_forks(t_fork *fork_head);
void		print_all_philos(t_philo *philos, size_t count);
void		print_context(t_context *ctx);

// Enum to string converters
const char	*sim_state_to_string(t_sim_state state);
const char	*philo_state_to_string(t_philo_state state);
#endif

