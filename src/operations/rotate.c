/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 15:49:23 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int rotate_list(t_list **lst, char *operation)
{
	t_list	*tmp;
	t_list	*new_list;
	t_list	*delete;

	tmp = *lst;
	if (!tmp->next)
		return (ERROR);
	while (tmp->next)
		tmp = tmp->next;
	new_list = createlst(tmp->value);
	if (!new_list)
		return (MALLOC_ERR);
	addfrontlst(&(*lst), new_list);
	while ((*lst)->next)
		*lst = (*lst)->next;
	delete = *lst;
	*lst = delete->next;
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
