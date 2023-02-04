/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:00:10 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/04 16:14:35 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_list *createlst(int value)
{
    t_list  *r_list;

    r_list = malloc (sizeof(t_list));
    if (!r_list)
        return (NULL);
    r_list->value = value;
    r_list->next = NULL;
    return (r_list);
}

void    addback(t_list **lst, t_list *new)
{
    t_list  *tmp = *lst;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new;
}
