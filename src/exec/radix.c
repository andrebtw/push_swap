/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:05:34 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 17:19:39 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


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
				rotate(stack, 'a');
			else
				push(stack, 'b');
			size--;
		}
		while (top_element(&(stack->b)) != -1)
			push(stack, 'a');
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
	radix_loop(&radix_p, stack);
	return (EXIT_SUCCESS);
}
