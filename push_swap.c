/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 19:16:31 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/13 17:40:18 by tfleming         ###   ########.fr       */
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
	search->maximum = 2;
	search->current = -1;
	search->minimum_check_depth = 0;
	search->operators = malloc(search->maximum * sizeof(t_operator));
	search->sorted_numbers = make_solution(length, array);
}

void				push_swap(int length, int array[length])
{
	t_stack			first;
	t_stack			second;
	t_search		search;

	setup_stacks(&first, &second, length, array);
	setup_search(&search, length, array);
	while (length > 1)
	{
		calculate_operators(&search, &first, &second);
		if (search.solution)
			break ;
		else
		{
			search.maximum += 2;
			search.minimum_check_depth += 2;
//			ft_putstr("\rNo solutions found, increasing maximum depth to ");
//			ft_putnbr(search.maximum);
		}
	}
	print_operators(search.solution, search.solution_length);
	ft_putchar('\n');
}
