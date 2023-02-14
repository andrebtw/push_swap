/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:19:01 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 16:10:51 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	stack_create(t_stack *stack, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (i < parsing->list_size)
	{
		if (i == 0)
		{
			stack->a = createlst(parsing->index_list[i]);
			if (!stack->a)
				return (MALLOC_ERR);
		}
		else if (addendvalue(&(stack->a), parsing->index_list[i]) == MALLOC_ERR)
			return (MALLOC_ERR);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	list_index(t_parsing *parsing)
{
	int			i;
	int			saved_index;
	long long	low_nb;

	parsing->index_list = (int *) malloc (parsing->list_size * sizeof(int));
	if (!parsing->index_list)
		return (MALLOC_ERR);
	parsing->index = 1;
	while (parsing->index < parsing->list_size + 1)
	{
		low_nb = LONG_LONG_MAX;
		i = -1;
		while (++i < parsing->list_size)
		{
			if (low_nb > parsing->list[i])
			{
				low_nb = parsing->list[i];
				saved_index = i;
			}
		}
		parsing->index_list[saved_index] = parsing->index;
		parsing->index++;
		parsing->list[saved_index] = LONG_LONG_MAX;
	}
	return (EXIT_SUCCESS);
}

int	list_create(char **argv, t_parsing *parsing)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		parsing->list[parsing->index] = ft_atoi_long(argv[i]);
		parsing->index++;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parsing(char **argv, t_stack *stack)
{
	t_parsing	parsing_v;

	parsing_v.index = 0;
	parsing_v.list = (long long *) malloc (sizeof(long long) * ft_tablen(argv));
	parsing_v.list_size = ft_tablen(argv) - 1;
	if (!parsing_v.list)
		return (MALLOC_ERR);
	stack->b = NULL;
	if (list_create(argv, &parsing_v) == MALLOC_ERR)
		return (free(parsing_v.list), MALLOC_ERR);
	if (list_index(&parsing_v) == MALLOC_ERR)
		return (free(parsing_v.list), MALLOC_ERR);
	if (stack_create(stack, &parsing_v) == MALLOC_ERR)
	{
		free(parsing_v.list);
		free(parsing_v.index_list);
		freelst(&(stack->a));
		return (MALLOC_ERR);
	}
	free(parsing_v.list);
	free(parsing_v.index_list);
	return (EXIT_SUCCESS);	
}
