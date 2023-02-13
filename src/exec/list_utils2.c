/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:52 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 20:02:10 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	second_element(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	tmp = tmp->next;
	return (tmp->value);
}

int	before_last_element(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next)
			tmp2 = tmp2->next;
	}
	return (tmp2->value);
}

int	third_element(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	tmp = tmp->next;
	tmp = tmp->next;
	return (tmp->value);
}

int	list_max2(t_list **lst, int max_nb)
{
	int		max_nb2;
	t_list	*tmp;

	tmp = *lst;
	max_nb2 = INT_MIN;
	while (tmp->next)
	{
		if (tmp->value > max_nb2 && tmp->value < max_nb)
			max_nb2 = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > max_nb2 && tmp->value < max_nb)
		max_nb2 = tmp->value;
	return (max_nb2);
}
