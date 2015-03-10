#include "push_swap.h"

void				swap(t_stack *stack)
{
	ft_intswp(&stack->first->number, &stack->first->next->number);
	add_to_solution(stack->solution, stack->swap_stack);
}

void				push(t_stack *destination, t_stack *source)
{
	t_entry			*moving;

	moving = source->first;
	if (!moving)
		ft_putendl_exit("trying to move from empty list", 1); // nope
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

void					rotate(t_stack *stack)
{
	if (stack->first != stack->first->next)
	{
		stack->first = stack->first->next;
		add_to_solution(stack->solution, stack->rotate_stack);
	}
}

void				reverse_rotate(t_stack *stack)
{
	if (stack->first != stack->first->previous)
	{
		stack->first = stack->first->previous;
		add_to_solution(stack->solution, stack->reverse_rotate_stack);
	}
}
