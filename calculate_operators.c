/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:47 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/09 21:06:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_finished(t_stack *first, t_stack *second, int *solution)
{
	if (second->count == 0)
	{
		if (first->begin == first->data)
			return (ft_memcmp(first->data, solution
								, first->length * sizeof(int)) == 0);
		if (ft_memcmp(first->begin, solution
					  , (first->length - (first->begin - first->data))
							* sizeof(int))
			|| ft_memcmp(first->data, solution + (first->length
											- (first->begin - first->data))
						, (first->begin - first->data) * sizeof(int)))
			return (0);
		return (1);
	}
	return (0);
}

static void			found_solution(t_search *search)
{
	size_t			solution_bytes;

	search->solution_length = search->current + 1;
	solution_bytes = search->solution_length * sizeof(t_operator);
	search->solution = malloc(solution_bytes);
	ft_memcpy(search->solution, search->operators, solution_bytes);
	search->maximum = search->current;
}

t_bool				calculate_operators(t_search *search, t_stack *first
										, t_stack *second)
{
	if (is_finished(first, second, search->sorted_numbers))
	{
		found_solution(search);
		return (1);
	}
	if (search->current >= search->maximum)
		return (0);
	search->current++;
	if (try_swap(search, first, second)
		|| try_push(search, first, second)
		|| try_rotate(search, first, second)
		|| try_reverse_rotate(search, first, second))
		search->current--;
	else
		search->current--;
	return (0);
}
