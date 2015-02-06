/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:16:31 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/05 15:59:38 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_swap(int length, int array[length])
{
	t_stack			first;
	t_stack			second;
	t_search		search;

	first.data = array;
	first.begin = first.data;
	first.count = length;
	first.length = length;
	second.data = malloc(sizeof(int) * length);
	second.begin = second.data;
	second.count = 0;
	second.length = length;
	ft_bzero(&search, sizeof(t_search));
	search.maximum = MAX_DEPTH;
	search.operators = malloc(search.maximum * sizeof(t_operator));
	if (length > 1)
	{
		calculate_operators(&search, &first, &second);
		if (!search.solution)
			ft_putstr("NO SOLUTION FOUND!\n");// change
	}
	print_operators(search.solution, search.solution_length);
}
