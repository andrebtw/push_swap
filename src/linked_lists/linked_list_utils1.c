/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:34:29 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 16:16:17 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstdelone(t_list *lst)
{
	free(lst);
}

void	freelst(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}

t_list	*createlst(long long value)
{
	t_list	*r_list;

	r_list = malloc (sizeof(t_list));
	if (!r_list)
		return (NULL);
	r_list->value = value;
	r_list->next = NULL;
	return (r_list);
}

int	createarglst(t_list **lst, long long value)
{
	*lst = malloc (sizeof(t_list));
	if (!(*lst))
		return (MALLOC_ERR);
	(*lst)->value = value;
	(*lst)->next = NULL;
	return (EXIT_SUCCESS);
}
