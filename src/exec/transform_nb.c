/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:03:20 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/09 17:26:18 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

typedef struct s_transform
{
	int	min_nb;
	int	index;
}	t_transform;

void	check_loop(t_list **lst, t_transform *transform)
{
	t_list	*tmp;
	size_t	counter;

	counter = 0;
	tmp = *lst;
	while (tmp->next)
	{
		if (counter == 0)
			transform->min_nb = tmp->value;
		if (tmp->value < transform->min_nb)
			transform->min_nb;
		tmp = tmp->next;
		counter++;
	}
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->value == transform->min_nb)

		tmp = tmp->next;
	}
}

void	transform_nb(t_stack *stack)
{
	t_transform	transform;

	transform.min_nb = 0;
	transform.index = 1;
}
