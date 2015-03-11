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

static int			count_sorted_at_end(t_entry *current, int length)
{
	int				i;

	i = 0;
	while (i < length - 1)
	{
		current = current->next;
		i++;
	}
	i = 0;
	while (i < length - 1 && current->number > current->previous->number)
	{
		current = current->previous;
		i++;
	}
	return (i);
}

void				print_debug(t_stack *destination, t_stack *source) // nope
{
	ft_putstr("source = ");
	print_entries(source->first);
	ft_putstr("\ndestination = ");
	print_entries(destination->first);
	ft_putstr("\n\n");
}

static int			push_if_necessary(t_stack *destination, t_stack *source
									  , int source_length)
{
	int				pivot;
	int				pushed;
	int				i;

	pivot = get_pivot(source->first, source_length);
	ft_putstr("beginning of push_if_necessary:\nlength = ");
	ft_putnbr(source_length);
	ft_putstr("\npivot = ");
	ft_putnbr(pivot);
	ft_putstr("\n");
	print_debug(destination, source);
	pushed = 0;
	i = 0;
	while (i < source_length)
	{
		
		if (source->first->number < pivot)
		{
			push(destination, source);
			ft_putstr("after push:\n");
			print_debug(destination, source);
			pushed++;
		}
		else
		{
			rotate(source);
			ft_putstr("after rotate:\n");
			print_debug(destination, source);
		}
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

/* static t_entry		*nth_entry(t_entry *first, int n) */
/* { */
/* 	int				i; */

/* 	i = 1; */
/* 	while (i < n) */
/* 	{ */
/* 		first = first->next; */
/* 		i++; */
/* 	} */
/* 	return (first); */
/* } */

void				partition_to_cutoff(t_stack *destination
										, t_stack *source
										, int source_length)
{
	int				pushed;
	int				sorted_at_end;

	//	ft_putstr("partitioning\n");
	sorted_at_end = count_sorted_at_end(source->first, source_length);
	source_length -= sorted_at_end;
	if (source_length <= PARTITION_CUTOFF)
		cutoff_reached(source, source_length);
	else
	{
		pushed = push_if_necessary(destination, source, source_length);
		do_n_times(reverse_rotate, source, source_length - pushed);
		partition_to_cutoff(source, destination, pushed);
		partition_to_cutoff(destination, source, source_length - pushed);
	}
	do_n_times(rotate, source, sorted_at_end);
}
