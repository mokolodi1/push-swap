/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:25:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 15:33:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				swap(t_stack *stack)
{
	ft_intswp(&stack->first->number, &stack->first->next->number);
	add_to_solution(stack->solution, stack->swap_stack);
	if (DEBUG) ft_printf("after swap:              ");
	if (DEBUG) print_entries(stack->first);
	if (DEBUG) ft_printf("\n\n");
}

void				push(t_stack *destination, t_stack *source)
{
	t_entry			*moving;

	moving = source->first;
	moving->previous->next = moving->next;
	moving->next->previous = moving->previous;
	source->first = (source->first->next == moving ? NULL : moving->next);
	moving->next = (destination->first
						? destination->first : moving);
	moving->previous = (destination->first
						? destination->first->previous : moving);
	moving->next->previous = moving;
	moving->previous->next = moving;
	destination->first = moving;
	add_to_solution(source->solution, destination->push_to_this_stack);
	if (DEBUG) ft_printf("after push:\n");
	if (DEBUG) print_debug(destination, source);
}

void					rotate(t_stack *stack)
{
	if (stack->first != stack->first->next)
	{
		stack->first = stack->first->next;
		add_to_solution(stack->solution, stack->rotate_stack);
	}
	if (DEBUG) ft_printf("after rotate:            ");
	if (DEBUG) print_entries(stack->first);
	if (DEBUG) ft_printf("\n\n");
}

void				reverse_rotate(t_stack *stack)
{
	if (stack->first != stack->first->previous)
	{
		stack->first = stack->first->previous;
		add_to_solution(stack->solution, stack->reverse_rotate_stack);
	}
	if (DEBUG) ft_printf("after reverse rotate:    ");
	if (DEBUG) print_entries(stack->first);
	if (DEBUG) ft_printf("\n\n");
}
