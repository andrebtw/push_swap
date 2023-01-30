/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:07:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/30 17:07:22 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	put_char_error(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (write(2, &string[i], 1) == -1)
			return (ERROR);
		i++;
	}
	return (0);
}

int	error_printing(void)
{
	if (put_char_error("Error\n") == ERROR)
		ft_putstr("STDERR IS CLOSED.");
	return (ERROR);
}
