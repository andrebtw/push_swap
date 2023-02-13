/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:27:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 17:05:00 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	nb_size_bits(int number)
{
	int	i;

	i = 0;
	while (number != 0)
	{
		number = number / 2;
		i++;
	}
	return (i);
}