/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 00:56:32 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 19:24:55 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_solved(t_try *try, t_search *search)
{
	if (try->second_length)
		return (0);
	if (ft_memcmp(try->first, search->ascending_numbers
						, try->first_length * sizeof(int)) == 0)
		return (1);
	return (0);
}

void				permutate(t_search *search)
{
	t_try			*best;
	t_operator		last_operator;

	best = ft_pq_remove(search->pq);
	last_operator = best->depth
						? best->operators[best->depth - 1] : NO_OPERATOR;
	if ((!search->solution || best->depth < search->solution_length)
		&& is_solved(best, search))
		found_solution(best, search);
	else if (!search->solution || best->depth < search->solution_length - 1)
	{
		add_swaps(best, search, last_operator);
		add_pushes(best, search, last_operator);
		add_rotates(best, search, last_operator);
		add_reverse_rotates(best, search, last_operator);
	}
	free_try(best);
	search->permutation_count++;
}
