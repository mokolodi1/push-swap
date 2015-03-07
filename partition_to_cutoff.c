/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_to_cutoff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:09:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/07 14:30:40 by tfleming         ###   ########.fr       */
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
	// todo: this
}

void				partition_to_cutoff(t_stack *destination
										, t_stack *source
										, int destination_length
										, int source_length)
{
	int				pivot;
	t_entry			*entry;
	int				pushed;

	if (source_length <= HARDCODED_CUTOFF)
		cutoff_reached(entry, destination_length, solution);
	else
	{
		entry = source->entries;
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
