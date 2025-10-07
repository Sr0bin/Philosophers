/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:14:47 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/07 13:28:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
// Needed to properly use usleep()
# define _XOPEN_SOURCE 500 

/**
 *     __           _ _ _     
 *    / _\_   _ ___| (_) |__  
 *    \ \| | | / __| | | '_ \ 
 *    _\ \ |_| \__ \ | | |_) |
 *    \__/\__, |___/_|_|_.__/ 
 *        |___/               
 */

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

/**
 *                          _               
 *      /\  /\___  __ _  __| | ___ _ __ ___ 
 *     / /_/ / _ \/ _` |/ _` |/ _ \ '__/ __|
 *    / __  /  __/ (_| | (_| |  __/ |  \__ \
 *    \/ /_/ \___|\__,_|\__,_|\___|_|  |___/
 *                                          
 */

# include "struct.h"
# include "mutex.h"
# include "fork.h"
# include "debug.h"
# include "context.h"
# include "parsing.h"
# include "thread.h"
# include "timer.h"

#endif
