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

static int			get_pivot(t_entry *entries, int length)
{
	// todo: optimize to look through all entries and find median
	(void)length;
	return (entries->number);
}

static void			push(t_stack *destination, t_stack *source)
{
	t_entry			*moving;

	moving = source->entries;
	if (!moving)
		ft_putstr("trying to push NULL! (partition_to_cutoff)\n"); // nope
	if (moving->last)
		moving->last->next = moving->next;
	if (moving->next)
		moving->next->last = moving->last;
	source->entries = moving->next;
	moving->next = destination->entries;
	moving->last = (destination->entries ? destination->entries->last : NULL);
	if (moving->next)
		moving->next->last = moving;
	if (moving->last)
		moving->last->next = moving;
	destination->entries = moving;
}

static void			rotate(t_stack *

static void			cutoff_reached(t_stack *stack, int length)
{
	if (length == 1)
	{
		add_to_solution(stack->solution, stack->rotate_stack);
		
	}
	(void)stack;
	(void)length;
	ft_putstr("cutoff_reached: code this now\n");
}

void				partition_to_cutoff(t_stack *destination
										, t_stack *source
										, int source_length)
{
	int				pivot;
	t_entry			*entry;
	int				pushed;
	int				i;

	entry = source->entries;
	if (source_length <= PARTITION_CUTOFF)
		cutoff_reached(source, source_length);
	else
	{
		pivot = get_pivot(entry, source_length);
		pushed = 0;
		i = 0;
		// optimization: only loop through until all have been moved
		while (i < source_length)
		{
			if (entry->number < pivot)
			{
				push(destination, source);
				add_to_solution(source->solution
								, destination->push_to_this_stack);
				pushed++;
			}
			add_to_solution(source->solution, source->rotate_stack);
			entry = entry->next;
			i++;
		}
		i = 0;
		while (i < source_length - pushed)
		{
			add_to_solution(source->solution, source->reverse_rotate_stack);
			i++;
		}
		partition_to_cutoff(source, destination, pushed);
		partition_to_cutoff(destination, source, source_length - pushed);
	}
}
