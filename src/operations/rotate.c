/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 20:43:09 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int rotate_list(t_list **lst, char *operation)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (!tmp->next)
			break ;
		tmp2 = tmp2->next;
	}
	addfrontlst(lst, tmp);
	tmp2->next = NULL;
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
