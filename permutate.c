/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 00:56:32 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 00:58:01 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_solved(t_try *try, t_search *search)
{
	if (try->second_length)
		return (0);
	return (ft_memcmp(try->first, search->ascending_numbers
							, try->first_length * sizeof(int)) == 0);
}

void				permutate(t_search *search)
{
	t_try			*best;

	best = ft_pq_remove(search->pq);
	if ((!search->solution || best->depth < search->solution_length)
		&& is_solved(best, search))
		found_solution(best, search);
	else if (!search->solution || best->depth < search->solution_length - 1)
	{
		add_swaps(best, search);
		add_pushes(best, search);
		add_rotates(best, search);
		add_reverse_rotates(best, search);
	}
	free_try(best);
	search->permutation_count++;
}
