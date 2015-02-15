#include "push_swap.h"

void				add_rotates(t_try *old, t_search *search)
{
	t_operator		last_operator;

	last_operator = old->depth ? old->operators[old->depth - 1] : 0;
	if (old->first_length > 2
		&& (last_operator >= SWAP_S || !last_operator))
		ft_pq_add(search->pq, create_first_swapped(old));
	if (old->second_length > 2
		&& (last_operator >= SWAP_S || !last_operator))
		ft_pq_add(search->pq, create_second_swapped(old));
	if (old->first_length > 2 && old->second_length > 2
		&& (last_operator != SWAP_S || !last_operator))
		ft_pq_add(search->pq, create_both_swapped(old));
}
