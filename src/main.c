/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:07:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/30 18:01:21 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init(char **argv)
{
	t_stack	stack;

	if (parsing(argv, &(stack)) == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}

int	main(int args, char **argv)
{
	if (errors(args, argv) == ERROR)
		return (ERROR);
	if (init(argv) == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}