/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:45:55 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 02:06:37 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int r_rotate_list(t_list **lst, char *operation)
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

void	reverse_rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->a)
			return ;
		r_rotate_list(&(stack->a), "rra\n");
	}
	if (c == 'b')
	{
		if (!stack->b)
			return ;
		r_rotate_list(&(stack->b), "rrb\n");
	}
	if (c == 'r')
	{
		if (!stack->b || !stack->a)
			return ;
		r_rotate_list(&(stack->a), "rrr\n");
		r_rotate_list(&(stack->b), NULL);
	}
}
