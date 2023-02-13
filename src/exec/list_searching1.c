/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_searching1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:24:17 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 15:07:30 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_sorted(t_list **lst, int inverse)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (inverse)
			if (tmp->value > tmp2->value)
				return (0);
		if (!inverse)
			if (tmp->value < tmp2->value)
				return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}

int	list_max(t_list **lst)
{
	int		max_nb;
	t_list	*tmp;

	tmp = *lst;
	max_nb = INT_MIN;
	while (tmp->next)
	{
		if (tmp->value > max_nb)
			max_nb = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > max_nb)
		max_nb = tmp->value;
	return (max_nb);
}

int	top_element(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return (0);
	return (tmp->value);
}

int	last_element(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

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
