/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:01:19 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/13 14:08:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	exec(int args, t_stack *stack)
{
	if (is_sorted(&(stack->a), 0))
		return (EXIT_SUCCESS);
	if (args - 1 == 2)
		if (two_(stack, 'a') == MALLOC_ERR)
			return (MALLOC_ERR);
	if (args - 1 == 3)
		if (three_(stack, 'a', 0) == MALLOC_ERR)
			return (MALLOC_ERR);
	if (args - 1 == 4)
		if (four_(stack) == MALLOC_ERR)
			return (MALLOC_ERR);
	if (args - 1 == 5)
		if (five_(stack) == MALLOC_ERR)
			return (MALLOC_ERR);
	if (args - 1 >= 6)
		if (radix(stack) == MALLOC_ERR)
			return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
