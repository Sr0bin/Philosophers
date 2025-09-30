/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:55:59 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 18:01:48 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
#include <bits/types/struct_timeval.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct timeval t_timeval;
typedef struct s_fork t_fork;


typedef struct s_int_mutex
{
	pthread_mutex_t	mutex;
	int				val;
}	t_mutex_int;

typedef struct s_mutex_bool
{
	pthread_mutex_t	mutex;
	bool			val;
}	t_mutex_bool;

typedef	struct	s_fork
{
	int	index;
	t_mutex_bool	state;
	t_fork *next;
}	t_fork;

typedef struct	s_fork_pair
{
	t_fork	*left;
	t_fork	*right;
}	t_fork_pair;

typedef	struct	s_context
{
	t_timeval	time_start;
	int			philo_max;
}	t_context;

typedef	enum e_philo_state
{
	HUNGRY,
	EATING,
	THINKING,
	DEAD
}	t_philo_state;

typedef struct s_philo
{
	int				index;
	t_philo_state	state;
	t_timeval		time_latest;
	t_fork_pair		pair;
}	t_philo;
#endif
