/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:03:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 13:16:59 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	list_max(t_list **lst)
{
	int		max_nb;
	t_list	*tmp;

	tmp = *lst;
	max_nb = INT_MIN;
	while (tmp->next)
	{
		if (tmp->value > max_nb)
			max_nb = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > max_nb)
		max_nb = tmp->value;
	return (max_nb);
}

int	top_element(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	return (tmp->value);
}

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
