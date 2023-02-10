/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:59:23 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 12:14:14 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	cmp(t_list **lst)
{
	int		temp_value;
	t_list	*tmp;

	tmp = *lst;
	temp_value = tmp->value;
	tmp = tmp->next;
	if (temp_value > tmp->value)
		return (0);
	return (1);
}

int	two_(t_stack *stack, char c)
{
	if (c == 'a')
		if (!cmp(&(stack->a)))
			swap(stack, 'a');
	if (c == 'b')
		if (!cmp(&(stack->a)))
			swap(stack, 'a');
	return (EXIT_SUCCESS);
}
