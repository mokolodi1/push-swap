/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:34:37 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/13 18:10:34 by tfleming         ###   ########.fr       */
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
										, t_stack *first, t_stack *second
										, t_operator last_operator)
{
	t_bool			found;
// I still need to finish this
	if (first->count
		&& (!last_operator || (last_operator != REVERSE_ROTATE_A
								&& last_operator != REVERSE_ROTATE_A_B)))
	{
		rotate(first);
		search->operators[search->current] = ROTATE_A;
		found = calculate_operators(search, first, second);
		reverse_rotate(first);
		if (found)
			return (1);
	}
	if (second->count
		&& (!last_operator || (last_operator != REVERSE_ROTATE_B
								&& last_operator != REVERSE_ROTATE_A_B)))
	{
		rotate(second);
		search->operators[search->current] = ROTATE_B;
		found = calculate_operators(search, first, second);
		reverse_rotate(second);
		if (found)
			return (1);
	}
	if (first->count && second->count
		&& (!last_operator || (last_operator != REVERSE_ROTATE_A
								&& last_operator != REVERSE_ROTATE_B
								&& last_operator != REVERSE_ROTATE_A_B)))
	{
		rotate(first);
		search->operators[search->current] = ROTATE_A_B;
		found = calculate_operators(search, first, second);
		reverse_rotate(first);
		reverse_rotate(second);
		if (found)
			return (1);
	}
	return (0);
}

t_bool				try_reverse_rotate(t_search *search
										, t_stack *first, t_stack *second
										, t_operator last_operator)
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
