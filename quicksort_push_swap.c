/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:47:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 18:54:26 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			convert_to_entries(t_entry *entries
										, int length, int *numbers)
{
	int				i;

	entries = malloc(length * sizeof(t_entry));
	i = 0;
	while (i < length)
	{
		entries[i].number = numbers[i];
		entries[i].last = entries + i - 1;
		entries[i].next = entries + i + 1;
		i++;
	}
	entries[0].last = entries + length - 1;
	entries[length - 1].next = entries;
}

static void			merge(t_stack *first_stack, t_stack *second_stack)
{
	t_entry			*first;
	t_entry			*second;

	first = first_stack->entries;
	second = second_stack->entries;
	while (1)
	{
		if (second == second_stack->entries->last
			|| (first != first_stack->entries->last
				&& first->number < second->number))
			first = first->next;
		else
		{
			add_to_solution(first_stack->solution, PUSH_A);
			second = second->next;
		}
		add_to_solution(first_stack->solution, ROTATE_A);
		if (first == first_stack->entries->last
			&& second == second_stack->entries->last)
			break ;
	}
}

// start here: make it so that the last element on linked lists is
// null (it won't be circular)

void				quicksort_push_swap(int length, int *numbers)
{
	t_solution		solution;
	t_entry			first_entries[length];
	t_stack			first;
	t_stack			second;

	solution.malloc_length = STARTING_SOLUTION_LENGTH;
	solution.length = 0;
	solution.operators = malloc(solution.length * sizeof(t_operator));
	convert_to_entries(first_entries, length, numbers);
	first.entries = first_entries;
	first.solution = &solution;
	first.push_to_this_operator = PUSH_A;
	first.rotate_this_operator = ROTATE_A;
	second.entries = NULL;
	second.solution = &solution;
	first.push_to_this_operator = PUSH_B;
	second.rotate_this_operator = ROTATE_B;
	partition_to_cutoff(&first, &second, length, 0);
	merge(&first, &second);
	print_operators(solution.length, solution.operators);
}
