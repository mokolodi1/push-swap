/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_to_cutoff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:09:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 15:59:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			get_pivot(t_entry *entries)
{
	// todo: optimize to look through all entries and find median
	return (entries->number);
}

static void			push(t_stack *destination, t_stack *source)
{
	t_entry			*moving;

	moving = source->entries;
	moving->last->next = moving->next;
	moving->next->last = moving->last;
	source->entries = moving->next;
	moving->next = destination->entries;
	moving->last = destination->entries->last;
	moving->next->last = moving;
	moving->last->next = moving;
	destination->entries = moving;
}

static void			cutoff_reached(t_stack *stack, int length)
{
	if (length == 1)
	{
		stack->entries = stack->entries->next;
		add_to_solution(stack->solution, stack->rotate_this_operator);
	}
}

void				partition_to_cutoff(t_stack *destination
										, t_stack *source
										, int destination_length
										, int source_length)
{
	int				pivot;
	t_entry			*entry;
	int				pushed;

	entry = source->entries;
	if (source_length <= PARTITION_CUTOFF)
		cutoff_reached(source, source_length);
	else
	{
		
		pivot = get_pivot(entry);
		pushed = 0;
		while (entry)
		{
			if (entry->number < pivot)
			{
				push(destination, source);
				add_to_solution(source->solution
								, destination->push_to_this_operator);
				pushed++;
			}
			entry = entry->next;
		}
		partition_to_cutoff(source, destination
							, source_length
							, pushed);
		partition_to_cutoff(destination, source
							, destination_length
							, source_length - pushed);
	}
}
