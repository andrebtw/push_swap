/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:03:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 16:40:56 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	four_last(t_stack *stack, int counter)
{
	while (counter < 3)
	{
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		counter++;
	}
	three_(stack, 'b', 1);
	while (counter)
	{
		if (push(stack, 'a') == MALLOC_ERR)
			return (MALLOC_ERR);
		counter--;
	}
	return (EXIT_SUCCESS);
}

int	four_(t_stack *stack)
{
	int	counter;
	int	max_nb;

	max_nb = list_max(&(stack->a));
	counter = 0;
	while (max_nb != top_element(&(stack->a)) && counter < 3)
	{
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		counter++;
	}
	if (counter != 3)
		if (rotate(stack, 'a') == MALLOC_ERR)
			return (MALLOC_ERR);
	if (four_last(stack, counter) == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
