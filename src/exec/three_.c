/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:01:11 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 11:41:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_rra(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	tmp = tmp->next;
	tmp2 = tmp2->next;
	tmp2 = tmp2->next;
	if (tmp2->value < tmp->value)
		return (1);
	return (0);
}

int	check_swap(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	tmp2 = tmp2->next;
	if (tmp2->value < tmp->value)
		return (1);
	return (0);
}

int	sort_three(t_stack *stack)
{
	if (check_swap(&(stack->a)))
		swap(stack, 'a');
	if (check_rra(&(stack->a)))
		reverse_rotate(stack, 'a');
	return (EXIT_SUCCESS);
}

int	three_(t_stack *stack)
{
	while (!is_sorted(&(stack->a)))
		sort_three(stack);
	return (EXIT_SUCCESS);
}
