/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:27:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 15:25:21 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	find_same_nb(t_list **lst, int nb)
{
	int		times;
	t_list	*tmp;

	tmp = *lst;
	times = 0;
	while (tmp->next)
	{
		if (tmp->value == nb)
			times++;
		tmp = tmp->next;
	}
	if (tmp->value == nb)
		times++;
	return (times);
}

int	list_min_modulo(t_list **lst, int modulo)
{
	int		min_nb;
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return (0);
	min_nb = INT_MAX;
	while (tmp->next)
	{
		if ((tmp->value % modulo) < min_nb)
			min_nb = (tmp->value % modulo);
		tmp = tmp->next;
	}
	if ((tmp->value % modulo) < min_nb)
		min_nb = (tmp->value % modulo);
	return (min_nb);
}
