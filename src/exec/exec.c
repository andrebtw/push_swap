/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:01:19 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 11:31:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_sorted(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value < tmp2->value)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}

int	exec(int args, t_stack *stack)
{
	if (args - 1 == 2)
		if (two_(stack) == MALLOC_ERR)
			return (MALLOC_ERR);
	if (args - 1 == 3)
		if (three_(stack) == MALLOC_ERR)
			return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
