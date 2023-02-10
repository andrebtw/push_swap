/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:01:11 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 13:12:18 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_rra(t_list **lst, int inverse)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	tmp = tmp->next;
	tmp2 = tmp2->next;
	tmp2 = tmp2->next;
	if (!inverse)
		if (tmp2->value < tmp->value)
			return (1);
	if (inverse)
		if (tmp2->value > tmp->value)
			return (1);
	return (0);
}

int	check_swap(t_list **lst, int inverse)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	tmp2 = tmp2->next;
	if (!inverse)
		if (tmp2->value < tmp->value)
			return (1);
	if (inverse)
		if (tmp2->value > tmp->value)
			return (1);
	return (0);
}

int	sort_three(t_stack *stack, char c, int inverse)
{
	if (c == 'a')
	{
		if (check_swap(&(stack->a), inverse))
			swap(stack, c);
		if (check_rra(&(stack->a), inverse))
			reverse_rotate(stack, c);
	}
	if (c == 'b')
	{
		if (check_swap(&(stack->b), inverse))
			swap(stack, c);
		if (check_rra(&(stack->b), inverse))
			reverse_rotate(stack, c);
	}
	return (EXIT_SUCCESS);
}

int	three_(t_stack *stack, char c, int inverse)
{
	if (c == 'a')
	{
		while (!is_sorted(&(stack->a), inverse))
			sort_three(stack, c, inverse);
	}
	if (c == 'b')
	{
		while (!is_sorted(&(stack->b), inverse))
			sort_three(stack, c, inverse);
	}
	return (EXIT_SUCCESS);
}
