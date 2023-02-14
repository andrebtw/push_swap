/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:08:45 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 17:43:30 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

# define ERROR -10
# define MALLOC_ERR -20
# define EXIT_SUCCESS 0
# define STDOUT 1
# define STDERR 2

/* NUMBERS */
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_LONG_MIN -9223372036854775807
# define LONG_LONG_MAX 9223372036854775806

/* LINKED LISTS*/
typedef struct s_linked_list
{
	long long	value;
	void		*next;
}	t_list;

t_list		*createlst(long long value);
void		addendlst(t_list **lst, t_list *new);
void		freelst(t_list	**lst);
void		printlist(t_list **lst);
int			addendvalue(t_list **lst, long long value);
void		addfrontlst(t_list **lst, t_list *new);
int			createarglst(t_list **lst, long long value);

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

/* PARSING */
int			parsing(char **argv, t_stack *stack);
typedef struct s_parsing
{
	long long	*list;
	int			*index_list;
	int			index;
	int			list_size;
	int			is_quoted;
}	t_parsing;

/* OPERATIONS */
void		swap(t_stack *stack, char c);
int			push(t_stack *stack, char c);
int			rotate(t_stack *stack, char c);
void		reverse_rotate(t_stack *stack, char c);

/* EXEC */
int			exec(int args, t_stack *stack);
int			is_sorted(t_list **lst, int inverse);
int			list_max(t_list **lst);
int			top_element(t_list **lst);
int			last_element(t_list **lst);
int			second_element(t_list **lst);
int			before_last_element(t_list **lst);
int			third_element(t_list **lst);
int			two_(t_stack *stack, char c);
int			three_(t_stack *stack, char c, int inverse);
int			four_(t_stack *stack);

typedef struct s_five
{
	int	counter;
	int	max_nb;
	int	max_nb2;
	int	reverse;
}	t_five;

int			five_(t_stack *stack);
int			loop_reverse2(t_stack *stack, t_five *five);
int			loop_not_reverse(t_stack *stack, t_five *five);
int			loop_reverse(t_stack *stack, t_five *five);
int			main_loop(t_stack *stack, t_five *five);
int			radix(t_stack *stack);
int			list_size(t_list **lst);
int			list_max2(t_list **lst, int max_nb);

typedef struct s_radix
{
	int	bin_index;
	int	list_size;
}	t_radix;

/* LIBC FUNCTIONS */
size_t		ft_strlen(char *string);
void		ft_putstr(char *string);
int			ft_isdigit(int c);
size_t		ft_tablen(char **tab);
int			ft_atoi(const char *nptr);
long long	ft_atoi_long(const char *nptr);

#endif
