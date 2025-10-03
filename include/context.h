/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 07:01:42 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# include "struct.h"

t_context	*context_init(int argc, char **argv);
void		*context_destroy(t_context **context_ptr);
t_philo		*philo_array_populate(t_context	*context);
void		add_meal(t_philo *philo);
#endif
