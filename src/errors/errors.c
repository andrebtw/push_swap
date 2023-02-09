/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:45:15 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/09 23:14:43 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_mult_size(char **argv)
{
	int	*tab;
	int	tab_size;
	int	tab_index;
	int	i;

	i = 1;
	tab_size = 0;
	tab = (int *) malloc (ft_tablen(argv) * 4);
	if (!tab)
		return (MALLOC_ERR);
	while (argv[i])
	{
		tab_index = 0;
		if (ft_atoi_long(argv[i]) > INT_MAX || ft_atoi_long(argv[i]) < INT_MIN)
			return (error_printing());
		while (tab_index != tab_size)
		{
			if (ft_atoi_long(argv[i]) == tab[tab_index])
				return (free(tab), error_printing());
			tab_index++;
		}
		tab_size++;
		tab[tab_index] = ft_atoi_long(argv[i]);
		i++;
	}
	return (free(tab), EXIT_SUCCESS);
}

int	check_chars(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				if (argv[i][j] != '-')
					return (error_printing());
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	errors(int argc, char **argv)
{
	if (argc == 1)
		return (ERROR);
	if (check_chars(argv) != EXIT_SUCCESS)
		return (ERROR);
	if (check_mult_size(argv) != EXIT_SUCCESS)
		return (ERROR);
	return (EXIT_SUCCESS);
}
