/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:37:15 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 19:13:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push(t_stack *source, t_stack *destination)
{
	if (!source->count)
		return (0);
	if (
	return (1);
}

void				try_push(t_search *search, t_stack *first, t_stack *second)
{
	if (push(first, second))
	{
		search->operators[search->current] = PUSH_A;
		calculate_operators(search, first, second);
		push(second, first);
	}
	if (push(second, first))
	{
		search->operators[search->current] = PUSH_B;
		calculate_operators(search, first, second);
		push(first, second);
	}
}
