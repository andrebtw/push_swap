/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:05:34 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 15:26:40 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


int	radix_loop(t_radix *radix, t_stack *stack)
{
	while (top_element(&(stack->a)))
	{
		radix->min_nb = list_min_modulo(&(stack->a), radix->modulo);
		radix->same_nb = find_same_nb(&(stack->a), radix->min_nb);
		while (radix->same_nb)
		{
			if (top_element(&(stack->a)) == radix->min_nb)
			{
				radix->same_nb--;
				push(stack, 'b');
			}
			rotate(stack, 'a');
		}
	}
	if (is_sorted(&(stack->b), 1))
	{
		while (top_element(&(stack->b)))
			push(stack, 'a');
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	radix(t_stack *stack)
{
	t_radix	radix_p;

	radix_p.modulo = 10;
	radix_loop(&radix_p, stack);
	return (EXIT_SUCCESS);
}
