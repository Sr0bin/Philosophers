/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:58:20 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:01:50 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	param_init(t_input input)
{
	t_param	param;

	param.time_const = time_init(input);
	param.philo_max = input.philo_max;
	param.max_meal = input.max_meal;
	return (param);
}
