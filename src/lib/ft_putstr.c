/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:42:57 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/27 18:45:07 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_putstr(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return ;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}
