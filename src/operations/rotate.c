/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 19:05:45 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	delete_elem(t_list **lst, int value)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value == value)
		{
			tmp2->next = NULL;
			return ;
		}
		tmp2 = tmp2->next;
	}	
	tmp->next = NULL;
	tmp = NULL;
	free(tmp);
}

static int rotate_list(t_list **lst, char *operation)
{
	t_list	*tmp;
	t_list	*new_list;

	tmp = *lst;
	if (!tmp->next)
		return (ERROR);
	while (tmp->next)
		tmp = tmp->next;
	new_list = createlst(tmp->value);
	if (!new_list)
		return (MALLOC_ERR);
	addfrontlst(&(*lst), new_list);
	delete_elem(lst, tmp->value);
	if (operation)
		ft_putstr(operation);
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
	if (c == 's')
	{
		if (!stack->b || !stack->a)
			return ;
		rotate_list(&(stack->a), "ss\n");
		rotate_list(&(stack->b), NULL);
	}
}
