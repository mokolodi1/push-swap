/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:37:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/13 18:06:56 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool		push(t_stack *source, t_stack *destination)
{
	if (!source->count)
		return (0);
	*GET_AFTER_LAST_NUMBER(destination) = *GET_LAST_NUMBER(source);
	source->count--;
	destination->count++;
	return (1);
}

t_bool				try_push(t_search *search, t_stack *first, t_stack *second
								, t_operator last_operator)
{
	t_bool			found;

	if ((!last_operator || last_operator != PUSH_B)
		&& push(first, second))
	{
		search->operators[search->current] = PUSH_A;
		found = calculate_operators(search, first, second);
		push(second, first);
		if (found)
			return (1);
	}
	if ((!last_operator || last_operator != PUSH_A)
		&& push(second, first))
	{
		search->operators[search->current] = PUSH_B;
		found = calculate_operators(search, first, second);
		push(first, second);
		if (found)
			return (1);
	}
	return (0);
}
