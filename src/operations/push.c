/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:02:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/05 16:36:15 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
/*
static void	push_list(t_list **a, t_list **b, char *operation)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	t_list	*new_list;
	int		value;

	new_list = createlst();
	tmp_a = *a;
	tmp_b = *b;
	tmp_a = tmp_a->next;
	if (!tmp_b->next)
		return ;
	tmp_b = tmp_b->next;
	value = tmp_b->value;
	new_list->value = value;
	addfrontlst(&(tmp_a), new_list);
	if (operation)
		ft_putstr(operation);
}
*/
void	push(t_stack *stack, char c)
{
	if (c == 'a')
		printf("test");
	if (c == 'b')
		printf("test");
}
