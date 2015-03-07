/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:11:02 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 18:40:19 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_to_solution(t_solution *solution, t_operator operator)
{
	if (solution->length >= solution->malloc_length)
	{
		ft_array_expand(solution->length * sizeof(t_operator)
						, solution->length * 2 * sizeof(t_operator)
						, (void**)&solution->operators);
		solution->malloc_length *= 2;
	}
	solution->operators[solution->length] = operator;
	solution->length++;
}
