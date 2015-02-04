/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:47 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 11:50:49 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_sorted(int *array, int length)
{
	int				i;

	i = 1;
	while (i < length)
	{
		if (array[i - 1] > array[i])
			return (0);
		i++;
	}
	return (1);
}

static int			is_finished(t_stack *first, t_stack *second)
{
	if (second->count == 0 && first->data == first->begin)
		return (is_sorted(first->data, first->length));
	return (0);
}

static void			found_solution(t_search *search)
{
	size_t			solution_bytes;

	search->solution_length = search->current;
	solution_bytes = search->solution_length * sizeof(t_operator);
	search->solution = malloc(solution_bytes);
	ft_memcpy(search->solution, search->operators, solution_bytes);
}

void				calculate_operators(t_search *search
										, t_stack *first, t_stack *second)
{
	if (is_finished(first, second))
	{
		found_solution(search);
		return ;
	}
	if (search->current + 1 == search->maximum)
		return ;
	search->current++;
	try_swap(search, first, second);
	try_push(search, first, second);
	try_rotate(search, first, second);
	try_reverse_rotate(search, first, second);
	search->current--;
}
