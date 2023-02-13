/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:02:47 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 20:04:50 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	addendvalue(t_list **lst, long long value)
{
	t_list	*tmp;
	t_list	*adding;

	tmp = *lst;
	adding = malloc (sizeof(t_list));
	if (!adding)
		return (MALLOC_ERR);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = adding;
	adding->value = value;
	adding->next = NULL;
	return (EXIT_SUCCESS);
}

void	addendlst(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	addfrontlst(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
