/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:39:59 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/07 13:32:07 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "struct.h"

/**
 *       ___               
 *      / __\___  _ __ ___ 
 *     / /  / _ \| '__/ _ \
 *    / /__| (_) | | |  __/
 *    \____/\___/|_|  \___|
 *                         
 */

void	*start_routine(void	*philo_struct);
int		thread_creation_loop(t_context *context);
void	*thread_destroy_philo(t_context *context);
/**
 *     __ _        _              _               _    
 *    / _\ |_ __ _| |_ ___    ___| |__   ___  ___| | __
 *    \ \| __/ _` | __/ _ \  / __| '_ \ / _ \/ __| |/ /
 *    _\ \ || (_| | ||  __/ | (__| | | |  __/ (__|   < 
 *    \__/\__\__,_|\__\___|  \___|_| |_|\___|\___|_|\_\
 *                                                     
 */

int		check_run(t_philo *philo);
void	sim_end(t_philo	*philo);
bool	philo_check_death(t_philo *philo);
bool	philo_check_ate(t_philo *philo);
bool	philo_check_sleep(t_philo *philo);

/**
 *     __ _        _         _                       _ _   _             
 *    / _\ |_ __ _| |_ ___  | |_ _ __ __ _ _ __  ___(_) |_(_) ___  _ __  
 *    \ \| __/ _` | __/ _ \ | __| '__/ _` | '_ \/ __| | __| |/ _ \| '_ \ 
 *    _\ \ || (_| | ||  __/ | |_| | | (_| | | | \__ \ | |_| | (_) | | | |
 *    \__/\__\__,_|\__\___|  \__|_|  \__,_|_| |_|___/_|\__|_|\___/|_| |_|
 *                                                                       
 */

void	philo_thinking_state(t_philo *philo);
void	philo_sleeping_state(t_philo *philo);
void	philo_eating_state(t_philo *philo);

/**
 *     __ _        _                    _       _   
 *    / _\ |_ __ _| |_ ___   _ __  _ __(_)_ __ | |_ 
 *    \ \| __/ _` | __/ _ \ | '_ \| '__| | '_ \| __|
 *    _\ \ || (_| | ||  __/ | |_) | |  | | | | | |_ 
 *    \__/\__\__,_|\__\___| | .__/|_|  |_|_| |_|\__|
 *                          |_|                     
 */

void	philo_print_death(t_philo	*philo, const char *msg);
void	philo_print_msg(t_philo	*philo, const char *msg);
#endif
