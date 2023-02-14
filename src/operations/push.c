/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:02:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 16:25:40 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_operation(char *operation)
{
	if (operation)
		ft_putstr(operation);
}

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
		if (createarglst(&(*a), tmp_b->value) == MALLOC_ERR)
			return (MALLOC_ERR);
		print_operation(operation);
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
	print_operation(operation);
	return (free(delete), delete = NULL, EXIT_SUCCESS);
}

int	push(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->b)
			return (EXIT_SUCCESS);
		push_list(&(stack->a), &(stack->b), "pa\n");
	}
	if (c == 'b')
	{
		if (!stack->a)
			return (EXIT_SUCCESS);
		if (push_list(&(stack->b), &(stack->a), "pb\n") == MALLOC_ERR)
			return (MALLOC_ERR);
	}
	return (EXIT_SUCCESS);
}
