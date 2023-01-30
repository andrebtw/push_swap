/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:08:45 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/30 18:30:23 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR -10
# define MALLOC_ERR -20
# define EXIT_SUCCESS 0
# define STDOUT 1
# define STDERR 2

/* STRUCTS */
typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
}	t_stack;

/* PUSH SWAP FUNCTIONS */
/* ERROR HANDLING FUNCTIONS */
int		errors(int argc, char **argv);
int		error_printing(void);

/* STACK CREATION FUNCTIONS */
int		parsing(char **argv, t_stack *stack);

/* LIBC FUNCTIONS */
size_t	ft_strlen(char *string);
void	ft_putstr(char *string);
int		ft_isdigit(int c);
size_t	ft_tablen(char **tab);
int		ft_atoi(const char *nptr);

#endif
