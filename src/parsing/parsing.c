/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:19:01 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/30 18:34:37 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	stack_create(char **argv, t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		stack->stack_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
}

int	parsing(char **argv, t_stack *stack)
{
	stack->stack_a = (int *) malloc (ft_tablen(argv) * sizeof(int));
	stack->stack_b = (int *) malloc (ft_tablen(argv) * sizeof(int));
	stack->stack_a[ft_tablen(argv)] = NULL;
	if (!stack->stack_a || !stack->stack_b)
		return (MALLOC_ERR);
	stack_create(argv, stack);
	printf("%d", stack->stack_a[0]);
	printf("%d", stack->stack_a[1]);
	printf("%d", stack->stack_a[2]);
	return (EXIT_SUCCESS);
}
