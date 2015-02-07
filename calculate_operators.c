/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_operators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:47 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/07 17:49:02 by tfleming         ###   ########.fr       */
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
						, (first->begin + first->count
							- (first->data + first->length)) * sizeof(int))
			|| ft_memcmp(first->data, solution
							, (first->begin - first->data) * sizeof(int)))
			return (0);
	}
	return (1);
}

static void			found_solution(t_search *search)
{
	size_t			solution_bytes;

	search->solution_length = search->current + 1;
	solution_bytes = search->solution_length * sizeof(t_operator);
	search->solution = malloc(solution_bytes);
	ft_memcpy(search->solution, search->operators, solution_bytes);
	search->maximum = search->solution_length - 1;
}

void				calculate_operators(t_search *search, t_stack *first
										, t_stack *second)
{
	if (is_finished(first, second, search->sorted_numbers))
	{
		found_solution(search);
		return ;
	}
	if (search->current >= search->maximum)
		return ;
	search->current++;
	try_swap(search, first, second);
	if (search->current >= search->maximum)
		return ;
	try_push(search, first, second);
	if (search->current >= search->maximum)
		return ;
	try_rotate(search, first, second);
	if (search->current >= search->maximum)
		return ;
	try_reverse_rotate(search, first, second);
	search->current--;
}
