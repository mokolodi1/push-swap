/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:34:37 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/09 17:41:18 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			rotate(t_stack *stack)
{
	*GET_BEFORE_FIRST_NUMBER(stack) = *GET_LAST_NUMBER(stack);
	stack->begin = GET_BEFORE_FIRST_NUMBER(stack);
}

static void			reverse_rotate(t_stack *stack)
{
	*GET_AFTER_LAST_NUMBER(stack) = *stack->begin;
	stack->begin = GET_AFTER_FIRST_NUMBER(stack);
}

/*
** todo: add "don't do these" to rotate methods (don't try rra after ra)
*/

t_bool				try_rotate(t_search *search
										, t_stack *first, t_stack *second)
{
	t_bool			found;

	rotate(first);
	search->operators[search->current] = ROTATE_A;
	found = calculate_operators(search, first, second);
	reverse_rotate(first);
	if (found)
		return (1);
	rotate(second);
	search->operators[search->current] = ROTATE_B;
	found = calculate_operators(search, first, second);
	if (found)
	{
		reverse_rotate(second);
		return (1);
	}
	rotate(first);
	search->operators[search->current] = ROTATE_A_B;
	found = calculate_operators(search, first, second);
	reverse_rotate(first);
	reverse_rotate(second);
	return (found);
}

t_bool				try_reverse_rotate(t_search *search
										, t_stack *first, t_stack *second)
{
	t_bool			found;

	reverse_rotate(first);
	search->operators[search->current] = REVERSE_ROTATE_A;
	found = calculate_operators(search, first, second);
	rotate(first);
	if (found)
		return (1);
	reverse_rotate(second);
	search->operators[search->current] = REVERSE_ROTATE_B;
	found = calculate_operators(search, first, second);
	if (found)
	{
		rotate(second);
		return (1);
	}
	reverse_rotate(first);
	search->operators[search->current] = REVERSE_ROTATE_A_B;
	found = calculate_operators(search, first, second);
	rotate(first);
	rotate(second);
	return (found);
}
