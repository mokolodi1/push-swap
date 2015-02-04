/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:36:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 19:04:34 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// could improve calculations in swap()

static void			swap_numbers(int *a, int *b)
{
	int				temporary;

	temporary = *b;
	*b = *a;
	*a = temporary;
}

static t_bool		swap(t_stack *s)
{
	int				*last;

	if (s->count < 2)
		return (0);
	if (s->begin + s->count <= s->data + s->length)
		swap_numbers(s->begin + s->count - 1, s->begin + s->count - 2);
	else if (s->begin + s->count == s->data + s->length + 1)
		swap_numbers(s->begin + s->count - 1, s->begin);
	else
	{
		// haven't checked this
		last = s->begin + s->count - s->length;
		swap_numbers(last - 1, last);
	}
	return (1);
}

void				try_swap(t_search *search, t_stack *first, t_stack *second)
{
	if (swap(first))
	{
		search->operators[search->current] = SWAP_A;
		calculate_operators(search, first, second);
		swap(first);
	}
	if (swap(second))
	{
		search->operators[search->current] = SWAP_B;
		calculate_operators(search, first, second);
		if (swap(first))
		{
			search->operators[search->current] = SWAP_S;
			calculate_operators(search, first, second);
			swap(first);
		}
		swap(second);
	}
}
