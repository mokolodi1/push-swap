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

void				permutate(t_search *search)
{
	t_try			*best;

	best = ft_pq_remove(search->pq);
	if (is_solved(best))
		found_solution(best, search);
	if (best->depth < max_depth)
	{
		add_swaps(best, search);
		add_pushes(best, search);
		add_rotates(best, search);
		add_reverse_rotates(best, search);
	}
	free_try(best);
	search->permutation_count++;
}
