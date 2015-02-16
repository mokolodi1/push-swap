#include "push_swap.h"

static t_try		create_rotate_first(t_try *old)
{
	
}

static t_try		create_rotate_second(t_try *old)
{
	
}

static t_try		create_rotate_both(t_try *old)
{
	
}

void				add_rotates(t_try *old, t_search *search)
{
	t_operator		last_operator;

	last_operator = old->depth ? old->operators[old->depth - 1] : 0;
	if (last_operator != REVERSE_ROTATE_A
		&& last_operator != REVERSE_ROTATE_A_B)
		ft_pq_add(search->pq, create_rotate_first(old));
	if (last_operator != REVERSE_ROTATE_B
		&& last_operator != REVERSE_ROTATE_A_B)
		ft_pq_add(search->pq, create_rotate_first(old));
	if (last_operator != REVERSE_ROTATE_A
		&& last_operator != REVERSE_ROTATE_B
		&& last_operator != REVERSE_ROTATE_A_B)
		ft_pq_add(search->pq, create_rotate_first(old));
}
