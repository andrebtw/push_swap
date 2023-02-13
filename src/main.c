/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:07:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 17:20:09 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init(int args, char **argv)
{
	t_stack	stack;

	if (parsing(argv, &(stack)) == MALLOC_ERR)
		return (MALLOC_ERR);
	//printlist(&(stack.a));
	exec(args, &stack);

	/*
	printf("A :\n");
	printlist(&(stack.a));
	printf("\n");
	printf("B :\n");
	printlist(&(stack.b));*/
	freelst(&(stack.a));
	freelst(&(stack.b));
	return (EXIT_SUCCESS);
}

int	main(int args, char **argv)
{
	if (errors(args, argv) == ERROR)
		return (ERROR);
	if (init(args, argv) == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
