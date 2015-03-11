/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:47:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 16:14:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			setup_entries(t_entry *entries, int length, int *numbers)
{
	int				i;

	i = 0;
	while (i < length)
	{
		entries[i].number = numbers[i];
		entries[i].previous = entries + i - 1;
		entries[i].next = entries + i + 1;
		i++;
	}
	entries[0].previous = entries + length - 1;
	entries[length - 1].next = entries;
}

static int			stack_length(t_stack *stack)
{
	t_entry			*current;
	int				count;
	
	current = stack->first;
	if (!current)
		return (0);
	if (current == current->previous)
		return (1);
	count = 1;
	while (current != stack->first->previous)
	{
		current = current->next;
		count++;
	}
	return (count);
}

static void			merge(t_stack *first_stack, t_stack *second_stack
												, int length)
{
	int				first_length;
	int				second_length;
	int				first_counter;
	int				second_counter;

	if (DEBUG) ft_printf("\n\nmerge:\n");
	if (DEBUG) print_debug(second_stack, first_stack);
	first_length = stack_length(first_stack);
	second_length = length - first_length;
	if (DEBUG) ft_printf("first_length = %d\nsecond_length = %d\n"
							, first_length, second_length);
	first_counter = 0;
	second_counter = 0;
	while (first_counter < first_length || second_counter < second_length)
	{
		if (DEBUG) ft_printf("first_counter = %d\n", first_counter);
		if (DEBUG) ft_printf("second_counter = %d\n", second_counter);
		if (first_counter >= first_length
				|| (second_counter < second_length
					&& first_stack->first->number > second_stack->first->number))
		{
			push(first_stack, second_stack);
			second_counter++;
		}
		else
			first_counter++;
		rotate(first_stack);
	}
}

static void			setup_stacks(t_stack *first_stack, t_stack *second_stack
								 , t_solution *solution, t_entry *entries)
{
	first_stack->first = entries;
	second_stack->first = NULL;
	first_stack->solution = solution;
	second_stack->solution = solution;
	first_stack->swap_stack = SWAP_A;
	second_stack->swap_stack = SWAP_B;
	first_stack->push_to_this_stack = PUSH_A;
	second_stack->push_to_this_stack = PUSH_B;
	first_stack->rotate_stack = ROTATE_A;
	second_stack->rotate_stack = ROTATE_B;
	first_stack->reverse_rotate_stack = REVERSE_ROTATE_A;
	second_stack->reverse_rotate_stack = REVERSE_ROTATE_B;
}

void				quicksort_push_swap(int length, int *numbers
										, t_operator **overall_solution
										, int *solution_length)
{
	t_solution		solution;
	t_entry			entries[length];
	t_stack			first_stack;
	t_stack			second_stack;

	solution.malloc_length = 2;
	solution.length = 0;
	solution.operators = malloc(solution.malloc_length * sizeof(t_operator));
	setup_entries(entries, length, numbers);
	setup_stacks(&first_stack, &second_stack, &solution, entries);
	partition_to_cutoff(&second_stack, &first_stack, length);
	if (second_stack.first)
		merge(&first_stack, &second_stack, length);
	*overall_solution = solution.operators;
	*solution_length = solution.length;
}
