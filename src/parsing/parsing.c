/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:19:01 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/05 16:57:52 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	stack_create(char **argv, t_stack *stack)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (i == 1)
		{
			stack->a = createlst(ft_atoi(argv[i]));
			if (!stack->a)
				return (MALLOC_ERR);
		}
		else if (addendvalue(&(stack->a), ft_atoi(argv[i])) == MALLOC_ERR)
			return (MALLOC_ERR);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parsing(char **argv, t_stack *stack)
{
	stack->b = NULL;
	if (stack_create(argv, stack) == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
