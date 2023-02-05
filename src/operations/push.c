/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:02:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/05 14:22:18 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	push_list(t_list **a, t_list **b, char *operation)
{
	t_list	*a_tmp;
	t_list	*b_tmp;
	int		tmp_value;

	a_tmp = *a;
	b_tmp = *b;
	a_tmp = a_tmp->next;
	if (!b_tmp->next)
		return ;
	b_tmp = b_tmp->next;
	tmp_value = a_tmp->value;
	a_tmp->value = b_tmp->value;
	b_tmp->value = tmp_value;
	write(1, &operation, 3);
}

void	push(t_stack *stack, char c)
{
	if (c == 'a')
		push_list(&(stack->a), &(stack->b), "pa\n");
	if (c == 'b')
		push_list(&(stack->b), &(stack->a), "pb\n");
}
