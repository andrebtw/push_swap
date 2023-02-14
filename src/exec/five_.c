/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:22:51 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/14 17:07:06 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

typedef struct s_five
{
	int	counter;
	int	max_nb;
	int	max_nb2;
	int	reverse;
}	t_five;

void	push_close(t_stack *stack, t_five *five)
{
	if ((five->max_nb == top_element(&(stack->a))
			|| five->max_nb2 == top_element(&(stack->a)))
		&& (five->max_nb == last_element(&(stack->a))
			|| five->max_nb2 == last_element(&(stack->a))))
	{
		push(stack, 'b');
		reverse_rotate(stack, 'a');
		push(stack, 'b');
		five->counter = 10;
	}
	if ((five->max_nb == second_element(&(stack->a))
			|| five->max_nb2 == second_element(&(stack->a)))
		&& (five->max_nb == last_element(&(stack->a))
			|| five->max_nb2 == last_element(&(stack->a))))
	{
		reverse_rotate(stack, 'a');
		push(stack, 'b');
		five->counter = 1;
		five->reverse = 0;
	}
}

void	config_and_reverse(t_stack *stack, t_five *five)
{
	five->max_nb = list_max(&(stack->a));
	five->max_nb2 = list_max2(&(stack->a), five->max_nb);
	five->counter = 0;
	five->reverse = 0;
	if (five->max_nb == last_element(&(stack->a))
		|| five->max_nb2 == last_element(&(stack->a)))
		if (five->max_nb == before_last_element(&(stack->a))
			|| five->max_nb2 == before_last_element(&(stack->a)))
			five->reverse = 1;
	if (five->max_nb == last_element(&(stack->a))
		|| five->max_nb2 == last_element(&(stack->a)))
		if (five->max_nb == third_element(&(stack->a))
			|| five->max_nb2 == third_element(&(stack->a)))
			if (third_element(&(stack->a)) > last_element(&(stack->a)))
				five->reverse = 1;
	push_close(stack, five);
}

int	loop_not_reverse(t_stack *stack, t_five *five)
{
	if (five->max_nb2 == top_element(&(stack->a)))
	{
		five->counter++;
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five->max_nb == top_element(&(stack->a)))
		{
			five->counter++;
			if (push(stack, 'b') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
	}
	if (five->max_nb == top_element(&(stack->a)))
	{
		five->counter++;
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five->max_nb2 == top_element(&(stack->a)))
		{
			five->counter++;
			if (push(stack, 'b') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
	}
}

int	loop_reverse(t_stack *stack, t_five *five)
{
	if (five->max_nb == last_element(&(stack->a)))
	{
		five->counter++;
		reverse_rotate(stack, 'a');
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five->max_nb2 == last_element(&(stack->a)))
		{
			five->counter++;
			reverse_rotate(stack, 'a');
			if (push(stack, 'b') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
	}
	if (five->max_nb2 == last_element(&(stack->a)))
	{
		five->counter++;
		reverse_rotate(stack, 'a');
		if (push(stack, 'b') == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five->max_nb == last_element(&(stack->a)))
		{
			five->counter++;
			reverse_rotate(stack, 'a');
			if (push(stack, 'b') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
	}
}

int	five_(t_stack *stack)
{
	t_five	five;

	config_and_reverse(stack, &five);
	while (five.counter < 2)
	{
		if (loop_not_reverse(stack, &five) == MALLOC_ERR)
			return (MALLOC_ERR);
		if (five.reverse)
		{
			if (loop_reverse(stack, &five) == MALLOC_ERR)
				return (MALLOC_ERR);
		}
		if (!five.reverse && five.counter < 2)
		{
			if (rotate(stack, 'a') == MALLOC_ERR)
				return (MALLOC_ERR);
		}
		else if (five.reverse == 1 && five.counter < 2)
			reverse_rotate(stack, 'a');
	}
	three_(stack, 'a', 0);
	if (push(stack, 'a') == MALLOC_ERR || push(stack, 'a') == MALLOC_ERR)
		return (MALLOC_ERR);
	two_(stack, 'a');
	if (rotate(stack, 'a') == MALLOC_ERR || rotate(stack, 'a') == MALLOC_ERR)
		return (MALLOC_ERR);
	return (EXIT_SUCCESS);
}
