/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/07 13:26:00 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# include "struct.h"

/**
 *       ___            _            _   
 *      / __\___  _ __ | |_ _____  _| |_ 
 *     / /  / _ \| '_ \| __/ _ \ \/ / __|
 *    / /__| (_) | | | | ||  __/>  <| |_ 
 *    \____/\___/|_| |_|\__\___/_/\_\\__|
 *                                       
 */

t_context	*context_init(int argc, char **argv);
void		*context_destroy(t_context **context_ptr);
t_philo		*philo_array_populate(t_context	*context);
void		add_meal(t_philo *philo);
#endif
