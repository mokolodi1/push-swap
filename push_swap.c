/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:16:31 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/07 17:41:31 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				setup_stacks(t_stack *first, t_stack *second
								 , int length, int array[length])
{
	first->data = array;
	first->begin = first->data;
	first->count = length;
	first->length = length;
	second->data = malloc(sizeof(int) * length);
	second->begin = second->data;
	second->count = 0;
	second->length = length;
}

int					*make_solution(int length, int array[length])
{
	int				*solution;

	solution = malloc(length * sizeof(int));
	ft_memcpy(solution, array, length * sizeof(int));
	ft_quicksort(length, solution);
	return (solution);
}

void				setup_search(t_search *search
									, int length, int array[length])
{
	ft_bzero(search, sizeof(t_search));
	search->maximum = MAX_DEPTH;
	search->operators = malloc(search->maximum * sizeof(t_operator));
	search->current = -1;
	search->sorted_numbers = make_solution(length, array);
}

void				push_swap(int length, int array[length])
{
	t_stack			first;
	t_stack			second;
	t_search		search;

	setup_stacks(&first, &second, length, array);
	setup_search(&search, length, array);
	if (length > 1)
	{
		calculate_operators(&search, &first, &second);
		if (!search.solution)
			ft_putstr("NO SOLUTION FOUND!\n");// change
	}
	print_operators(search.solution, search.solution_length);
}
