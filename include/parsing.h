/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:00:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/07 13:26:34 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "struct.h"

/**
 *       ___               _             
 *      / _ \__ _ _ __ ___(_)_ __   __ _ 
 *     / /_)/ _` | '__/ __| | '_ \ / _` |
 *    / ___/ (_| | |  \__ \ | | | | (_| |
 *    \/    \__,_|_|  |___/_|_| |_|\__, |
 *                                 |___/ 
 */

t_param	param_init(t_input input);
t_param	parsing(int argc, char **argv, int *ret);
size_t	ft_atoi(const char *nptr);
#endif
