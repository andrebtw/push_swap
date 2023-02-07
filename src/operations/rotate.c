/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 21:35:24 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	rotate_list(t_list **lst, char *operation)
{
	t_list	*tmp;
	t_list	*new_list;
	t_list	*delete;

	tmp = *lst;
	new_list = createlst(tmp->value);
	if (!new_list)
		return (MALLOC_ERR);
	addendlst(lst, new_list);
	delete = *lst;
	*lst = delete->next;
	free(delete);
	delete = NULL;
	return (EXIT_SUCCESS);
}

void	rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->a)
			return ;
		rotate_list(&(stack->a), "sa\n");
	}
	if (c == 'b')
	{
		if (!stack->b)
			return ;
		rotate_list(&(stack->b), "sb\n");
	}
	if (c == 'r')
	{
		if (!stack->b || !stack->a)
			return ;
		rotate_list(&(stack->a), "ss\n");
		rotate_list(&(stack->b), NULL);
	}
}
