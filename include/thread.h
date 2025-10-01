/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:39:59 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:45:21 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "struct.h"

int	thread_creation_loop(t_context *context);
void	*thread_destroy_philo(t_context *context);
#endif

