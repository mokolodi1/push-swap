/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:47:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 14:31:32 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			convert_to_entries(t_entry *entries
										, int lenght, int *numbers)
{
	int				i;

	entries = malloc(length * sizeof(t_entry));
	i = 0
	while (i < length)
	{
		entries[i].next = entries + i + 1;
		entries[i].data = numbers[i];
		i++;
	}
	entries[i - 1].next = NULL;
}

static void			merge(t_stack *first_stack, t_stack *second_stack)
{
	t_entry			*first;
	t_entry			*second;

	first = first_stack;
	second = second_stack;
	while (*first || *second)
	{
		if (*first && (first->number < second->number || !*second))
		{
			add_to_solution(first_stack->solution, ROTATE_A);
			first = first->next;
		}
		else
		{
			add_to_solution(first_stack->solution, PUSH_A);
			add_to_solution(first_stack->solution, ROTATE_B);
			second = second->next;
		}
	}
}

void				quicksort_push_swap(int length, int *numbers)
{
	t_solution		solution;
	t_entry			first_entries[length];
	t_stack			first;
	t_stack			second;

	solution.length = STARTING_SOLUTION_LENGTH;
	solution.current = 0;
	solution.operators = malloc(solution.length * sizeof(t_operator));
	convert_to_entries(first_entries, length, numbers);
	first.entries = first_entries;
	first.last = first_entires[length - 1];
	first.solution = &solution;
	first.push_to_this_operator = PUSH_A;
	second.entries = NULL;
	second.last = NULL;
	second.solution = &solution;
	first.push_to_this_operator = PUSH_B;
	partition_to_cutoff(&first, &second, length, 0);
	merge(&first, &second);
}
