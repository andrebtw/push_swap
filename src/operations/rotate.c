/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:08 by anrodri2         ###   ########.fr       */
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
	if (operation)
		ft_putstr(operation);
	return (EXIT_SUCCESS);
}

int	rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->a)
			return (EXIT_SUCCESS);
		if (rotate_list(&(stack->a), "ra\n") == MALLOC_ERR)
			return (MALLOC_ERR);
	}
	if (c == 'b')
	{
		if (!stack->b)
			return (EXIT_SUCCESS);
		if (rotate_list(&(stack->b), "rb\n") == MALLOC_ERR)
			return (MALLOC_ERR);
	}
	if (c == 'r')
	{
		if (!stack->b || !stack->a)
			return (EXIT_SUCCESS);
		if (rotate_list(&(stack->a), "rr\n") == MALLOC_ERR)
			return (MALLOC_ERR);
		if (rotate_list(&(stack->b), NULL) == MALLOC_ERR)
			return (MALLOC_ERR);
	}
	return (EXIT_SUCCESS);
}
