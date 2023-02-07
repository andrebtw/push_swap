/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:02:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 15:20:25 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	push_list(t_list **a, t_list **b, char *operation)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	t_list	*new_list;
	t_list	*delete;

	tmp_a = *a;
	tmp_b = *b;
	if (!tmp_a)
	{
		createarglst(&(*a), tmp_b->value);
		if (operation)
			ft_putstr(operation);
		delete = *b;
		*b = delete->next;
		return (free(delete), EXIT_SUCCESS);
	}
	new_list = createlst(tmp_b->value);
	if (!new_list)
		return (MALLOC_ERR);
	addfrontlst(&(*a), new_list);
	delete = *b;
	*b = delete->next;
	if (operation)
		ft_putstr(operation);
	return (free(delete), EXIT_SUCCESS);
}

void	push(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->b)
			return ;
		push_list(&(stack->a), &(stack->b), "pa\n");
	}
	if (c == 'b')
	{
		if (!stack->a)
			return ;
		push_list(&(stack->b), &(stack->a), "pb\n");
	}
}
