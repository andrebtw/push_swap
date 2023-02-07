/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:44:02 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 22:46:00 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_isspace(char character)
{
	if (character == ' ' || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r')
		return (1);
	return (0);
}

long long	ft_atoi_long(const char *nptr)
{
	long long		number;
	int				neg_mult;
	int				i;

	i = 0;
	number = 0;
	neg_mult = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		neg_mult = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		number = number * 10 + nptr[i++] - '0';
	return (neg_mult * number);
}
