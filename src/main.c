/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:14:38 by rorollin          #+#    #+#             */
/*   Updated: 2025/09/30 20:52:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "philo.h"

int	main(int argc, char **argv)
{
	t_fork	*fork;
	t_fork_pair	pair;

	fork = fork_list_create(15);
	print_forks(fork);
	pair = fork_pair_gen(fork, 7);
	print_fork_pair(&pair);
	fork_list_destroy(&fork);
	return (EXIT_SUCCESS);
}
