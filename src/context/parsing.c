/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:12:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/02 20:17:41 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_input	input_init	(int argc, char **argv)
{
	t_input	input;

	//add check for error
	if (argc < 5 || argc > 7)
		exit(EXIT_FAILURE);
	input.philo_max = ft_atoi(argv[1]);
	input.time_to_die = ft_atoi(argv[2]);
	input.time_to_eat = ft_atoi(argv[3]);
	input.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input.max_meal = ft_atoi(argv[5]);
	else
		input.max_meal = -1;
	return (input);
}

t_param	parsing(int argc, char **argv)
{
	int	i;
	t_input	input;
	t_param param;

	input = input_init(argc, argv);
	param = param_init(input);
	return (param);
}
