/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:18:03 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/03 03:39:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static size_t	ft_charstatus(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	if (c == '+' || c == '-')
		return (2);
	if (ft_isdigit(c))
		return (3);
	return (0);
}

static long long	ft_add_dec(const char *str)
{
	long long	count;
	size_t		i;
	size_t		length;

	count = 0;
	i = 0;
	length = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	while (ft_charstatus(str[i]) == 3)
	{
		length++;
		if (length >= 11)
			return (LONG_MAX);
		count *= 10;
		count += str[i] - '0';
		i++;
	}
	return (count);
}

size_t	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (ft_charstatus(nptr[i]))
	{
		while (ft_charstatus(nptr[i]) > 1)
		{
			if (ft_charstatus(nptr[i]) == 2)
			{
				if (nptr[i] == '-')
					return (LONG_MAX);
				i++;
			}
			return (sign * (int) ft_add_dec(&nptr[i]));
		}
		i++;
	}
	return (LONG_MAX);
}
