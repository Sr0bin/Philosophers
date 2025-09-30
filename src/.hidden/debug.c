/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:33:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 20:37:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex_int(t_mutex_int *mi, const char *name)
{
	if (!mi)
		return ;
	pthread_mutex_lock(&mi->mutex);
	printf("%s: %d\n", name, mi->val);
	pthread_mutex_unlock(&mi->mutex);
}

void	print_mutex_bool(t_mutex_bool *mb, const char *name)
{
	if (!mb)
		return ;
	pthread_mutex_lock(&mb->mutex);
	printf("%s: %s\n", name, mb->val ? "true" : "false");
	pthread_mutex_unlock(&mb->mutex);
}

void	print_fork(t_fork *fork)
{
	if (!fork)
	{
		printf("Fork: NULL\n");
		return ;
	}
	printf("Fork %d: ", fork->index);
	pthread_mutex_lock(&fork->state.mutex);
	printf("state=%s\n", fork->state.val ? "taken" : "available");
	pthread_mutex_unlock(&fork->state.mutex);
}

void	print_forks(t_fork *fork)
{
	t_fork	*current;
	t_fork	*start;
	int		count;

	if (!fork)
	{
		printf("Fork list is empty\n");
		return ;
	}
	start = fork;
	current = fork;
	count = 0;
	printf("=== Fork List ===\n");
	while (current)
	{
		print_fork(current);
		current = current->next;
		count++;
		if (current == start)
		{
			printf("(circular list: %d forks)\n", count);
			break ;
		}
	}
	if (current != start)
		printf("Total: %d forks\n", count);
}

void	print_fork_pair(t_fork_pair *pair)
{
	if (!pair)
	{
		printf("Fork pair: NULL\n");
		return ;
	}
	printf("=== Fork Pair ===\n");
	printf("Left:  ");
	if (pair->left)
		printf("Fork %d\n", pair->left->index);
	else
		printf("NULL\n");
	printf("Right: ");
	if (pair->right)
		printf("Fork %d\n", pair->right->index);
	else
		printf("NULL\n");
}

void	print_context(t_context *ctx)
{
	if (!ctx)
	{
		printf("Context: NULL\n");
		return ;
	}
	printf("=== Context ===\n");
	printf("Start time: %ld.%06ld\n", 
		ctx->time_start.tv_sec, 
		ctx->time_start.tv_usec);
	printf("Max philos: %d\n", ctx->philo_max);
}

const char	*philo_state_str(t_philo_state state)
{
	if (state == HUNGRY)
		return ("HUNGRY");
	if (state == EATING)
		return ("EATING");
	if (state == THINKING)
		return ("THINKING");
	if (state == DEAD)
		return ("DEAD");
	return ("UNKNOWN");
}

void	print_philo(t_philo *philo)
{
	if (!philo)
	{
		printf("Philosopher: NULL\n");
		return ;
	}
	printf("=== Philosopher %d ===\n", philo->index);
	printf("State: %s\n", philo_state_str(philo->state));
	printf("Latest time: %ld.%06ld\n",
		philo->time_latest.tv_sec,
		philo->time_latest.tv_usec);
	printf("Left fork:  %d\n", 
		philo->pair.left ? philo->pair.left->index : -1);
	printf("Right fork: %d\n",
		philo->pair.right ? philo->pair.right->index : -1);
}

void	print_all_philos(t_philo *philos, int count)
{
	int	i;

	printf("\n=== All Philosophers ===\n");
	i = 0;
	while (i < count)
	{
		print_philo(&philos[i]);
		printf("\n");
		i++;
	}
}
