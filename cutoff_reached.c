#include "push_swap.h"

void				cutoff_reached(t_stack *stack, int length)
{
	if (length == 1)
		rotate(stack);
	else if (length == 2)
	{
		if (stack->first->number > stack->first->next->number)
			swap(stack);
		rotate(stack);
		rotate(stack);
	}
	else
		ft_putendl_exit("cutoff reached too soon\n", 2);
	/* ft_putstr("cutoff reached:\nlength = "); */
	/* ft_putnbr(length); */
	/* ft_putstr("\n"); */
	/* print_entries(stack->first); */
	/* ft_putstr("\n"); */
}
