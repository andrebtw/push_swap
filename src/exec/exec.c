/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:01:19 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/10 00:10:34 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	exec(int args, t_stack *stack)
{
	if (args - 1 == 2)
		if (two_(stack) == MALLOC_ERR)
			return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
