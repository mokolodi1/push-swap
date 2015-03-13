/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutoff_reached.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:45:30 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/13 16:14:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			three_things_part_two(t_stack *destination, t_stack *source
											, int second, int third)
{
	if (second < third)
	{
		swap(destination, source);
		rotate(destination, source);
		swap(destination, source);
		rotate(destination, source);
		rotate(destination, source);
	}
	else
	{
		push(destination, source);
		push(destination, source);
		rotate(source, destination);
		rotate(source, destination);
		rotate(destination, source);
	}
}

static void			three_things_part_one(t_stack *destination, t_stack *source
											, int first, int second, int third)
{
	if (first < second)
	{
		swap(destination, source);
		push(destination, source);
		push(destination, source);
		rotate(source, destination);
		rotate(source, destination);
		rotate(destination, source);
	}
	else
		three_things_part_two(destination, source, second, third);
}

void				cutoff_reached(t_stack *destination, t_stack *source
														, int length)
{
	if (DEBUG) ft_printf("cutoff_reached: %d\n", length);
	if (length == 0)
		return ;
	if (length == 1)
	{
		if (source->first->next != source->first)
			rotate(destination, source);
	}
	else if (length == 2)
	{
		if (source->first->number > source->first->next->number)
			swap(destination, source);
		if (get_nth_entry(source->first, length) != source->first->previous)
		{
			rotate(destination, source);
			rotate(destination, source);
		}
	}
	else if (length == 3)
		three_things_part_one(destination, source, source->first->number
								, source->first->next->number
								, source->first->next->next->number);
}
