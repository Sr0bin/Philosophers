/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:55:59 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 20:10:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
#include <bits/types/struct_timeval.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define START_OFFSET 800000
# define USEC_PER_SEC 1000000
# define SLEEP_DELTA 100

typedef struct timeval	t_timeval;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;

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

typedef struct s_fork
{
	int				index;
	t_mutex_bool	state;
	t_fork			*next;
}	t_fork;

typedef struct s_fork_pair
{
	t_fork	*left;
	t_fork	*right;
}	t_fork_pair;

typedef enum e_sim_state
{
	PENDING,
	STARTED,
	FINISHED
}	t_sim_state;

typedef struct	s_time_const
{
	size_t		time_to_eat;
	size_t		time_to_die;
	size_t		time_to_sleep;
	t_timeval	sim_start;
}	t_time_const;

typedef struct s_input
{
	size_t		philo_max;
	size_t		time_to_eat;
	size_t		time_to_die;
	size_t		time_to_sleep;
	int			max_meal;
}	t_input;
typedef struct	s_param
{
	size_t				philo_max;
	t_time_const	time_const;
	int				max_meal;
}	t_param;
typedef	struct	s_context
{
	t_param			param;
	t_sim_state		state;
	t_fork			*fork_head;
	t_philo			*philos;
	t_mutex_bool	write_mutex;	
	t_mutex_bool	running;
}	t_context;

typedef	enum e_philo_state
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}	t_philo_state;

typedef struct s_timer
{
	t_timeval	w_start_time;
	t_timeval	w_crnt_time;
}	t_timer;

typedef struct s_philo
{
	size_t			index;
	pthread_t		th_id;
	t_philo_state	state;
	t_fork_pair		pair;
	int				meal;
	t_context	*context;
	t_timer		timer;
	int	ret;

}	t_philo;
#endif
