/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:22:51 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 17:07:12 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	list_max2(t_list **lst, int max_nb)
{
	int		max_nb2;
	t_list	*tmp;

	tmp = *lst;
	max_nb2 = INT_MIN;
	while (tmp->next)
	{
		if (tmp->value > max_nb2 && tmp->value < max_nb)
			max_nb2 = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > max_nb2 && tmp->value < max_nb)
		max_nb2 = tmp->value;
	return (max_nb2);
}

int	five_(t_stack *stack)
{
	int	counter;
	int	max_nb;
	int	max_nb2;
	int	reverse;

	max_nb = list_max(&(stack->a));
	max_nb2 = list_max2(&(stack->a), max_nb);
	reverse = 0;
	counter = 0;
	if (max_nb == last_element(&(stack->a)) ||
			max_nb2 == last_element(&(stack->a)))
		if (max_nb == before_last_element(&(stack->a)) ||
				max_nb2 == before_last_element(&(stack->a)))
			reverse = 1;
	if (max_nb == last_element(&(stack->a)) ||
			max_nb2 == last_element(&(stack->a)))
		if (max_nb == third_element(&(stack->a)) ||
				max_nb2 == third_element(&(stack->a)))
			if (third_element(&(stack->a)) > last_element(&(stack->a)))
				reverse = 1;
	if (max_nb == top_element(&(stack->a)) ||
			max_nb2 == top_element(&(stack->a)))
		if (max_nb == last_element(&(stack->a)) ||
			max_nb2 == last_element(&(stack->a)))
			{
				push(stack, 'b');
				reverse_rotate(stack, 'a');
				push(stack, 'b');
				counter = 10;
			}
	if (max_nb == second_element(&(stack->a)) ||
			max_nb2 == second_element(&(stack->a)))
		if (max_nb == last_element(&(stack->a)) ||
			max_nb2 == last_element(&(stack->a)))
			{
				reverse_rotate(stack, 'a');
				push(stack, 'b');
				counter = 1;
				reverse = 0;
			}
	while (counter < 2)
	{
		if (max_nb2 == top_element(&(stack->a)))
		{
			counter++;
			push(stack, 'b');
			if (max_nb == top_element(&(stack->a)))
			{
				counter++;
				push(stack, 'b');
			}
		}
		if (max_nb == top_element(&(stack->a)))
		{
			counter++;
			push(stack, 'b');
			if (max_nb2 == top_element(&(stack->a)))
			{
				counter++;
				push(stack, 'b');
			}
		}
		if (reverse)
		{
			if (max_nb == last_element(&(stack->a)))
			{
				counter++;
				reverse_rotate(stack, 'a');
				push(stack, 'b');
				if (max_nb2 == last_element(&(stack->a)))
				{
					counter++;
					reverse_rotate(stack, 'a');
					push(stack, 'b');
				}
			}
			if (max_nb2 == last_element(&(stack->a)))
			{
				counter++;
				reverse_rotate(stack, 'a');
				push(stack, 'b');
				if (max_nb == last_element(&(stack->a)))
				{
					counter++;
					reverse_rotate(stack, 'a');
					push(stack, 'b');
				}
			}
		}
		if (!reverse && counter < 2)
			rotate(stack, 'a');
		else if (reverse == 1 && counter < 2) 
			reverse_rotate(stack, 'a');
	}
	three_(stack, 'a', 0);
	push(stack, 'a');
	push(stack, 'a');
	two_(stack, 'a');
	rotate(stack, 'a');
	rotate(stack, 'a');
	return (EXIT_SUCCESS);
}
