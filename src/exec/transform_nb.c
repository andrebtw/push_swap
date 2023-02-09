/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:03:20 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/09 17:51:58 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

typedef struct s_transform
{
	int	min_nb;
	int	index;
}	t_transform;

int		is_indexed(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (!tmp->transformed_value)
			return (1);
		tmp = tmp->next;
	}
	return (1);
}

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
		if (tmp->value < transform->min_nb && !tmp->transformed_value)
			transform->min_nb = tmp->value;
		tmp = tmp->next;
		counter++;
	}
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->value == transform->min_nb && !tmp->transformed_value)
		{
			tmp->transformed_value = transform->index;
			transform->index++;
		}
		tmp = tmp->next;
	}
}

void	transform_nb(t_list	**lst)
{
	t_transform	transform;

	transform.min_nb = 0;
	transform.index = 1;
	while (!is_indexed(lst))
		check_loop(lst, &transform);
}
