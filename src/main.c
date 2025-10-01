/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:14:38 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 17:01:06 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "philo.h"

int	main(int argc, char **argv)
{
	t_context	*context;
	t_fork	*fork;
	t_fork_pair	pair;

	context = context_init(argc, argv);
	print_context(context);
	thread_creation_loop(context);
	context_destroy(&context);
	// fork = fork_list_create(15);
	// print_forks(fork);
	// pair = fork_pair_gen(fork, 7);
	// print_fork_pair(&pair);
	// fork_list_destroy(&fork);
	return (EXIT_SUCCESS);
}
