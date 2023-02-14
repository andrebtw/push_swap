/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:34:14 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 17:44:44 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	loop_reverse2(t_stack *stack, t_five *five)
{
	if (five->max_nb2 == last_element(&(stack->a)))
	{
		five->counter++;
		reverse_rotate(stack, 'a');
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five->max_nb == last_element(&(stack->a)))
		{
			five->counter++;
			reverse_rotate(stack, 'a');
			if (push(stack, 'b') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
	}
	return (EXIT_SUCCESS);
}

int	main_loop(t_stack *stack, t_five *five)
{
	while (five->counter < 2)
	{
		if (loop_not_reverse(stack, five) == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five->reverse)
		{
			if (loop_reverse(stack, five) == MALLOC_ERR)
				return (MALLOC_ERR);
		}
		if (!five->reverse && five->counter < 2)
		{
			if (rotate(stack, 'a') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
		else if (five->reverse == 1 && five->counter < 2)
			reverse_rotate(stack, 'a');
	}
	return (EXIT_SUCCESS);
}
