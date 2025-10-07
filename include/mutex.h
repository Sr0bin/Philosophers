/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:01:43 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/07 13:26:24 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H
# include "struct.h"

/**
 *                  _                ___             _ 
 *      /\/\  _   _| |_ _____  __   / __\ ___   ___ | |
 *     /    \| | | | __/ _ \ \/ /  /__\/// _ \ / _ \| |
 *    / /\/\ \ |_| | ||  __/>  <  / \/  \ (_) | (_) | |
 *    \/    \/\__,_|\__\___/_/\_\ \_____/\___/ \___/|_|
 *                                                     
 */

t_mutex_bool	mutex_bool_create(bool val, pthread_mutex_t *mem, int *error);
void			*mutex_bool_destroy(t_mutex_bool *mutex);
bool			mutex_bool_access(t_mutex_bool *mutex, int *error);
int				mutex_bool_unlock(t_mutex_bool *mutex);

/**
 *                  _               _____       _   
 *      /\/\  _   _| |_ _____  __   \_   \_ __ | |_ 
 *     /    \| | | | __/ _ \ \/ /    / /\/ '_ \| __|
 *    / /\/\ \ |_| | ||  __/>  <  /\/ /_ | | | | |_ 
 *    \/    \/\__,_|\__\___/_/\_\ \____/ |_| |_|\__|
 *                                                  
 */

t_mutex_int		mutex_int_create(int val, pthread_mutex_t *mem, int *error);
void			*mutex_int_destroy(t_mutex_int *mutex);
int				mutex_int_access(t_mutex_int *mutex, int *error);
int				mutex_int_unlock(t_mutex_int *mutex);
#endif
