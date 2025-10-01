/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:00:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/01 16:06:33 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "struct.h"

t_param	param_init(t_input input);
t_time_const	time_init(t_input input);
t_param	parsing(int argc, char **argv);
size_t	ft_atoi(const char *nptr);
#endif

