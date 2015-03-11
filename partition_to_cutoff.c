/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_to_cutoff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:09:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 16:11:34 by tfleming         ###   ########.fr       */
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
	if (DEBUG) ft_printf("\nbeginning of push_if_necessary:\n");
	if (DEBUG) ft_printf("length = %d\n", source_length);
	if (DEBUG) ft_printf("pivot =  %d\n", pivot);
	if (DEBUG) print_debug(destination, source);
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
			rotate(source);
		i++;
	}
	return (pushed);
}

static void			do_n_times(void (*f)(t_stack*), t_stack *stack, int number)
{
	int				i;

	i = 0;
	while (i < number)
	{
		f(stack);
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

	if (DEBUG) ft_printf("partition_to_cutoff:\n\n");
	source_length = count_unsorted(source->first, source_length
								   , &sorted_at_beginning, &sorted_at_end);
	if (get_nth_entry(source->first, sorted_at_beginning)
			!= source->first->previous)
		do_n_times(rotate, source, sorted_at_beginning);
	if (source_length <= PARTITION_CUTOFF)
		cutoff_reached(source, source_length);
	else
	{
		pushed = push_if_necessary(destination, source, source_length);
		if (DEBUG) ft_printf("reverse rotate source * %d\n\n"
							 , source_length - pushed);
		if (get_nth_entry(source->first
						  , source_length - pushed) != source->first->previous)
			do_n_times(reverse_rotate, source, source_length - pushed);
		partition_to_cutoff(source, destination, pushed);
		partition_to_cutoff(destination, source, source_length - pushed);
	}
	if (DEBUG) ft_printf("rotate source * %d\n\n", sorted_at_end);
	do_n_times(rotate, source, sorted_at_end);
}
