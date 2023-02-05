/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:38:48 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/05 17:06:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	swap_list(t_list **lst, char *operation)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		tmp_value;
	int		tmp_value2;

	tmp = *lst;
	if (!tmp->next)
		return ;
	tmp_value = tmp->value;
	tmp = tmp->next;
	tmp_value2 = tmp->value;
	tmp->value = tmp_value;
	tmp2 = *lst;
	tmp2->value = tmp_value2;
	if (operation)
		ft_putstr(operation);
}

void	swap(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->a)
			return ;
		swap_list(&(stack->a), "sa\n");
	}
	if (c == 'b')
	{
		if (!stack->b)
			return ;
		swap_list(&(stack->b), "sb\n");
	}
	if (c == 's')
	{
		if (!stack->b || !stack->a)
			return ;
		swap_list(&(stack->a), "ss\n");
		swap_list(&(stack->b), NULL);
	}
}
