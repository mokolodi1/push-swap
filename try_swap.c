/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:36:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 19:42:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			swap_numbers(int *a, int *b)
{
	int				temporary;

	temporary = *b;
	*b = *a;
	*a = temporary;
}

static t_bool		swap(t_stack *stack)
{
	if (stack->count < 2)
		return (0);
	swap_numbers(get_last_number(stack), get_before_last_number(stack));
	return (1);
}

void				try_swap(t_search *search, t_stack *first, t_stack *second)
{
	// first if doesn't work
	if (!search->current || *(search->operators + search->current) - 1 > SWAP_S)
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
}
