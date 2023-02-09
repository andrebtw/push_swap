/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:08:45 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/09 14:08:49 by anrodri2         ###   ########.fr       */
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

/* NUMBERS */
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/* LINKED LISTS*/
typedef struct s_linked_list
{
	int		value;
	int		transformed_value;
	void	*next;
	
}	t_list;

t_list		*createlst(int value);
void		addendlst(t_list **lst, t_list *new);
void		freelst(t_list	**lst);
void		printlist(t_list **lst);
int			addendvalue(t_list **lst, int value);
void		addfrontlst(t_list **lst, t_list *new);
void		createarglst(t_list **lst, int value);

/* STRUCTS */
typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

/* PUSH SWAP FUNCTIONS */
/* ERROR HANDLING FUNCTIONS */
int			errors(int argc, char **argv);
int			error_printing(void);

/* STACK CREATION FUNCTIONS */
int			parsing(char **argv, t_stack *stack);

/* OPERATIONS */
void		swap(t_stack *stack, char c);
void		push(t_stack *stack, char c);
void		rotate(t_stack *stack, char c);
void		reverse_rotate(t_stack *stack, char c);

/* EXEC */
void		transform_nb(t_stack *stack);

/* LIBC FUNCTIONS */
size_t		ft_strlen(char *string);
void		ft_putstr(char *string);
int			ft_isdigit(int c);
size_t		ft_tablen(char **tab);
int			ft_atoi(const char *nptr);
long long	ft_atoi_long(const char *nptr);

#endif
