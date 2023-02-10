/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:03:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 13:49:35 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	four_(t_stack *stack)
{
	int	counter;
	int	max_nb;

	max_nb = list_max(&(stack->a));
	counter = 0;
	while (max_nb != top_element(&(stack->a)) && counter < 3)
	{
		push(stack, 'b');
		counter++;
	}
	if (counter != 3)
		rotate(stack, 'a');
	while (counter < 3)
	{
		push(stack, 'b');
		counter++;
	}
	three_(stack, 'b', 1);
	while (counter)
	{
		push(stack, 'a');
		counter--;
	}
	return (EXIT_SUCCESS);
}
