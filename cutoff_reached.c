/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutoff_reached.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:45:30 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 16:13:01 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			three_things_part_two(t_stack *destination
										  , t_stack *source
								 , int second, int third)
{
	if (second < third)
	{
		swap(source);
		rotate(source);
		swap(source);
		rotate(source);
		rotate(source);
	}
	else
	{
		push(destination, source);
		push(destination, source);
		rotate(destination);
		rotate(destination);
		rotate(source);
	}
}

static void			three_things_part_one(t_stack *destination, t_stack *source
								 , int first, int second, int third)
{
	if (first < second)
	{
		swap(source);
		push(destination, source);
		push(destination, source);
		rotate(destination);
		rotate(destination);
		rotate(source);
	}
	else
		three_things_part_two(destination, source, second, third);
}

void				cutoff_reached(t_stack *destination, t_stack *source, int length)
{
	if (DEBUG) ft_printf("\ncutoff_reached:\n");
	if (length == 0)
		return ;
	if (length == 1)
	{
		if (source->first->next != source->first)
			rotate(source);
	}
	else if (length == 2)
	{
		if (source->first->number > source->first->next->number)
			swap(source);
		if (get_nth_entry(source->first, length) != source->first->previous)
		{
			if (DEBUG) ft_printf("should add rotates\n\n");
			rotate(source);
			rotate(source);
		}
	}
	else if (length == 3)
		three_things_part_one(destination, source, source->first->number
								, source->first->next->number
								, source->first->next->next->number);
	if (DEBUG) ft_printf("cutoff finished\n");
}
