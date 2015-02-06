/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:37:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 20:06:47 by tfleming         ###   ########.fr       */
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

void				try_push(t_search *search, t_stack *first, t_stack *second)
{
	if ((!search->current || *(search->operators + search->current) - 1 != PUSH_B)
		&& push(first, second))
	{
		search->operators[search->current] = PUSH_A;
		calculate_operators(search, first, second);
		push(second, first);
	}
	if ((!search->current || *(search->operators + search->current) - 1 != PUSH_A)
		&& push(second, first))
	{
		search->operators[search->current] = PUSH_B;
		calculate_operators(search, first, second);
		push(first, second);
	}
}
