/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:25:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/13 16:37:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				print_stack(t_stack *stack)
{
	t_entry			*current;
	ft_printf("[");
	if (!stack->first)
		ft_printf("none");
	else
	{
		current = stack->first;
		ft_printf("%d", current->number);
		current = current->next;
		while (current != stack->first)
		{
			ft_printf(" %d", current->number);
			current = current->next;
		}
	}
	ft_printf("]");
}

static int			last_operator_is(t_solution *solution, t_operator operator)
{
	if (solution->length > 0
		&& solution->operators[solution->length - 1] == operator)
		return (1);
	return (0);
}

static t_operator	current_operator(t_stack *stack)
{
	if (stack->solution->length > 0)
		return (stack->solution->operators[stack->solution->length]);
	else
		return (NO_OPERATOR);
}

void				swap(t_stack *destination, t_stack *source)
{
	t_solution		*solution;

	ft_intswp(&source->first->number, &source->first->next->number);
	solution = source->solution;
	if (last_operator_is(solution, source->swap_stack))
		solution->length--;
	else if (last_operator_is(solution, destination->swap_stack))
		solution->operators[solution->length] = SWAP_S;
	else
		add_to_solution(solution, source->swap_stack);
	if (DEBUG) ft_printf("after swap:             ");
	if (DEBUG) print_stack(source);
	if (DEBUG) ft_printf("\n");
}

void				push(t_stack *destination, t_stack *source)
{
	t_entry			*moving;

	if (last_operator_is(source->solution, source->push_to_this_stack))
		source->solution->length--;
	else
	{
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
	}
	if (DEBUG) ft_printf("after push:\n");
	if (DEBUG) ft_printf("source:                 ");
	if (DEBUG) print_stack(source);
	if (DEBUG) ft_printf("\ndestination:            ");
	if (DEBUG) print_stack(destination);
	if (DEBUG) ft_printf("\n\n");
}

void				rotate(t_stack *destination, t_stack *source)
{
	t_solution		*solution;

	if (source->first != source->first->next)
	{
		source->first = source->first->next;
		solution = source->solution;
		if (last_operator_is(solution, source->reverse_rotate_stack))
			solution->length--;
		else
		{
			if (current_operator(source) == destination->rotate_stack)
				solution->operators[solution->length] = ROTATE_A_B;
			else
				add_to_solution(solution, source->rotate_stack);
		}
		if (DEBUG) ft_printf("after rotate:           ");
		if (DEBUG) print_stack(source);
		if (DEBUG) ft_printf("\n");
	}
}

void				reverse_rotate(t_stack *destination, t_stack *source)
{
	t_solution		*solution;

	if (source->first != source->first->previous)
	{
		source->first = source->first->previous;
		solution = source->solution;
		if (last_operator_is(solution, source->rotate_stack))
			solution->length--;
		else
		{
			
			if (current_operator(source) == destination->rotate_stack)
				solution->operators[solution->length] =
					REVERSE_ROTATE_A_B;
			else
				add_to_solution(solution, source->reverse_rotate_stack);
		}
		if (DEBUG) ft_printf("after reverse rotate:   ");
		if (DEBUG) print_stack(source);
		if (DEBUG) ft_printf("\n");
	}
}
