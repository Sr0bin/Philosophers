/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:14:38 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/07 14:19:30 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "philo.h"

int	main(int argc, char **argv)
{
	t_context	*context;

	context = context_init(argc, argv);
	if (context == NULL)
	{
		printf("Problem in the parsing : check your arguments.\n");
		return (EXIT_FAILURE);
	}
	if (context->param.max_meal != 0)
		thread_creation_loop(context);
	context_destroy(&context);
	return (EXIT_SUCCESS);
}
