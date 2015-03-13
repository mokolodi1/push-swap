/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_to_cutoff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:09:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/13 15:08:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			count_unsorted(t_entry *current, int length
										 , int *begin_count
										 , int *end_count)
{
	int				numbers[length];

	convert_entries_to_array(current, length, numbers);
	ft_quicksort(length, numbers);
	*begin_count = 0;
	while (*begin_count < length && current->number == numbers[*begin_count])
	{
		current = current->next;
		(*begin_count)++;
	}
	*end_count = 0;
	if (*begin_count != length)
	{
		current = get_nth_entry(current, length - *begin_count);
		while (current->number == numbers[length - 1 - *end_count])
		{
			current = current->previous;
			(*end_count)++;
		}
	}
	return (length - *begin_count - *end_count);
}

static int			push_if_necessary(t_stack *destination, t_stack *source
									  , int source_length)
{
	int				pivot;
	int				pushed;
	int				i;

	pivot = get_pivot(source->first, source_length);
	pushed = 0;
	i = 0;
	while (i < source_length)
	{
		if (source->first->number < pivot)
		{
			push(destination, source);
			pushed++;
		}
		else
			rotate(destination, source);
		i++;
	}
	return (pushed);
}

static void			do_n_times(void (*f)(t_stack*, t_stack*)
								, t_stack *destination, t_stack *source
								, int number)
{
	int				i;

	i = 0;
	while (i < number)
	{
		f(destination, source);
		i++;
	}
}

void				partition_to_cutoff(t_stack *destination
										, t_stack *source
										, int source_length)
{
	int				pushed;
	int				sorted_at_beginning;
	int				sorted_at_end;

	source_length = count_unsorted(source->first, source_length
								   , &sorted_at_beginning, &sorted_at_end);
	if (get_nth_entry(source->first, sorted_at_beginning)
			!= source->first->previous)
		do_n_times(rotate, destination, source, sorted_at_beginning);
	if (source_length <= PARTITION_CUTOFF)
		cutoff_reached(destination, source, source_length);
	else
	{
		pushed = push_if_necessary(destination, source, source_length);
		if (get_nth_entry(source->first
						  , source_length - pushed) != source->first->previous)
			do_n_times(reverse_rotate, destination, source
						, source_length - pushed);
		partition_to_cutoff(source, destination, pushed);
		partition_to_cutoff(destination, source, source_length - pushed);
	}
	do_n_times(rotate, destination, source, sorted_at_end);
}
