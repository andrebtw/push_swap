/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:00:10 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/04 17:38:29 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	freelst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	free(tmp);
}

t_list	*createlst(void)
{
	t_list  *r_list;

	r_list = malloc (sizeof(t_list));
	if (!r_list)
    	return (NULL);
	r_list->next = NULL;
	return (r_list);
}

int	addendvalue(t_list **lst, int value)
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
	return (EXIT_SUCCESS);
}

void	addendlst(t_list **lst, t_list *new)
{
    t_list  *tmp;

    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void	printlist(t_list **lst)
{
	t_list  *tmp;

    tmp = *lst;
    while (tmp->next)
	{
		printf("%d\n", tmp->value);
        tmp = tmp->next;
	}
}
