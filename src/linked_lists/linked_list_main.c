/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:00:10 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/07 20:17:00 by anrodri2         ###   ########.fr       */
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

t_list	*createlst(int value)
{
	t_list  *r_list;

	r_list = malloc (sizeof(t_list));
	if (!r_list)
    	return (NULL);
	r_list->value = value;
	r_list->next = NULL;
	return (r_list);
}

void	createarglst(t_list **lst, int value)
{
	*lst = malloc (sizeof(t_list));
	if (!(*lst))
	{
		return ;
	}
	(*lst)->value = value;
	(*lst)->next = NULL;
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
	adding->next = NULL;
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

void	addfrontlst(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	printlist(t_list **lst)
{
	t_list  *tmp;

    tmp = *lst;
	if (!tmp)
		return ;
	printf("%d\n", tmp->value);
    while (tmp->next)
	{
        tmp = tmp->next;
		printf("%d\n", tmp->value);
	}
}
