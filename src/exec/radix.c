/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:05:34 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 16:56:56 by anrodri2         ###   ########.fr       */
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

int	radix_loop(t_radix *radix, t_stack *stack)
{
	int	bit_size;
	int	size;

	size = radix->list_size;
	bit_size = nb_size_bits(size);
	while (bit_size)
	{
		size = radix->list_size;
		while (size)
		{
			if (((top_element(&(stack->a)) >> radix->bin_index) & 1) == 1)
			{
				if (rotate(stack, 'a') == MALLOC_ERR)
					return (MALLOC_ERR);
			}
			else
			{
				if (push(stack, 'b') == MALLOC_ERR)
					return (MALLOC_ERR);
			}
			size--;
		}
		while (top_element(&(stack->b)) != -1)
		{
			if (push(stack, 'a') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
		radix->bin_index++;
		bit_size--;
	}
	return (EXIT_SUCCESS);
}

int	radix(t_stack *stack)
{
	t_radix	radix_p;

	radix_p.list_size = list_size(&(stack->a));
	radix_p.bin_index = 0;
	if (radix_loop(&radix_p, stack) == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
