/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:33:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:05:41 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Print function for t_mutex_int
void	print_mutex_int(const char *name, t_mutex_int *mi)
{
	if (!mi)
	{
		printf("%s: (NULL)\n", name);
		return;
	}
	printf("%s: { val: %d }\n", name, mi->val);
}

// Print function for t_mutex_bool
void	print_mutex_bool(const char *name, t_mutex_bool *mb)
{
	if (!mb)
	{
		printf("%s: (NULL)\n", name);
		return;
	}
	printf("%s: { val: %s }\n", name, mb->val ? "true" : "false");
}

// Print function for t_fork
void	print_fork(t_fork *fork)
{
	if (!fork)
	{
		printf("Fork: (NULL)\n");
		return;
	}
	printf("Fork: { index: %d, state: %s, next: %p }\n",
		fork->index,
		fork->state.val ? "taken" : "available",
		(void *)fork->next);
}

// Print all forks in circular list
void	print_all_forks(t_fork *fork_head)
{
	t_fork	*current;
	int		count;

	if (!fork_head)
	{
		printf("Forks: (NULL)\n");
		return;
	}
	printf("=== Forks List ===\n");
	current = fork_head;
	count = 0;
	do
	{
		printf("  [%d] index: %d, state: %s\n",
			count,
			current->index,
			current->state.val ? "taken" : "available");
		current = current->next;
		count++;
	} while (current && current != fork_head);
	printf("==================\n");
}

// Print function for t_fork_pair
void	print_fork_pair(const char *name, t_fork_pair *pair)
{
	if (!pair)
	{
		printf("%s: (NULL)\n", name);
		return;
	}
	printf("%s: {\n", name);
	printf("  left:  { index: %d, state: %s }\n",
		pair->left ? pair->left->index : -1,
		(pair->left && pair->left->state.val) ? "taken" : "available");
	printf("  right: { index: %d, state: %s }\n",
		pair->right ? pair->right->index : -1,
		(pair->right && pair->right->state.val) ? "taken" : "available");
	printf("}\n");
}

// Print function for t_sim_state
const char	*sim_state_to_string(t_sim_state state)
{
	if (state == PENDING)
		return "PENDING";
	if (state == STARTED)
		return "STARTED";
	if (state == FINISHED)
		return "FINISHED";
	return "UNKNOWN";
}

// Print function for t_time_const
void	print_time_const(t_time_const *tc)
{
	if (!tc)
	{
		printf("TimeConst: (NULL)\n");
		return;
	}
	printf("TimeConst: {\n");
	printf("  time_to_eat:   %zu ms\n", tc->time_to_eat);
	printf("  time_to_die:   %zu ms\n", tc->time_to_die);
	printf("  time_to_sleep: %zu ms\n", tc->time_to_sleep);
	printf("  sim_start:     %ld.%06ld\n",
		tc->sim_start.tv_sec,
		tc->sim_start.tv_usec);
	printf("}\n");
}

// Print function for t_input
void	print_input(t_input *input)
{
	if (!input)
	{
		printf("Input: (NULL)\n");
		return;
	}
	printf("Input: {\n");
	printf("  philo_max:     %zu\n", input->philo_max);
	printf("  time_to_eat:   %zu ms\n", input->time_to_eat);
	printf("  time_to_die:   %zu ms\n", input->time_to_die);
	printf("  time_to_sleep: %zu ms\n", input->time_to_sleep);
	printf("  max_meal:      %d\n", input->max_meal);
	printf("}\n");
}

// Print function for t_param
void	print_param(t_param *param)
{
	if (!param)
	{
		printf("Param: (NULL)\n");
		return;
	}
	printf("Param: {\n");
	printf("  philo_max: %zu\n", param->philo_max);
	printf("  max_meal:  %d\n", param->max_meal);
	print_time_const(&param->time_const);
	printf("}\n");
}

// Print function for t_philo_state
const char	*philo_state_to_string(t_philo_state state)
{
	if (state == EATING)
		return "EATING";
	if (state == THINKING)
		return "THINKING";
	if (state == SLEEPING)
		return "SLEEPING";
	if (state == DEAD)
		return "DEAD";
	return "UNKNOWN";
}

// Print function for t_philo
void	print_philo(t_philo *philo)
{
	if (!philo)
	{
		printf("Philo: (NULL)\n");
		return;
	}
	printf("Philo: {\n");
	printf("  index:     %d\n", philo->index);
	printf("  thread_id: %lu\n", (unsigned long)philo->thread_id);
	printf("  state:     %s\n", philo_state_to_string(philo->state));
	printf("  meal:      %d\n", philo->meal);
	printf("  forks:     left=%d, right=%d\n",
		philo->pair.left ? philo->pair.left->index : -1,
		philo->pair.right ? philo->pair.right->index : -1);
	printf("}\n");
}

// Print all philosophers
void	print_all_philos(t_philo *philos, size_t count)
{
	size_t	i;

	if (!philos)
	{
		printf("Philos: (NULL)\n");
		return;
	}
	printf("=== Philosophers ===\n");
	i = 0;
	while (i < count)
	{
		printf("[%zu] index: %d, state: %s, meals: %d, forks: L%d/R%d\n",
			i,
			philos[i].index,
			philo_state_to_string(philos[i].state),
			philos[i].meal,
			philos[i].pair.left ? philos[i].pair.left->index : -1,
			philos[i].pair.right ? philos[i].pair.right->index : -1);
		i++;
	}
	printf("====================\n");
}

// Print function for t_context
void	print_context(t_context *ctx)
{
	if (!ctx)
	{
		printf("Context: (NULL)\n");
		return;
	}
	printf("====== CONTEXT ======\n");
	printf("Simulation State: %s\n", sim_state_to_string(ctx->state));
	printf("\n");
	print_param(&ctx->param);
	printf("\n");
	print_all_forks(ctx->fork_head);
	printf("\n");
	print_all_philos(ctx->philos, ctx->param.philo_max);
	printf("=====================\n");
}
