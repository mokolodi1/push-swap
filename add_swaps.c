#include "push_swap.h"

static t_try		*create_first_swapped(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->first = malloc((old->first_length + 1) * sizeof(int));
	ft_memcpy(new->first, old->first, old->first_length * sizeof(int));
	ft_intswp(new->first, new->first + 1);
	new->first[new->first_length] = 0;
	new->second = old->second;
	new->second[new->second_length]++;
	new->operators[new->depth - 1] = SWAP_A;
	set_score(new);
	return (new);
}

static t_try		*create_second_swapped(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->second = malloc((old->second_length + 1) * sizeof(int));
	ft_memcpy(new->second, old->second, old->second_length * sizeof(int));
	ft_intswp(new->second, new->second + 1);
	new->second[new->second_length] = 0;
	new->first = old->first;
	new->first[new->first_length]++;
	new->operators[new->depth - 1] = SWAP_B;
	set_score(new);
	return (new);
}

static t_try		*create_both_swapped(t_try *old
											, t_try *first_swapped
											, t_try *second_swapped)
{
	t_try			*new;

	new = create_general_try(old);
	new->first = first_swapped->first;
	new->second = second_swapped->second;
	new->first[new->first_length]++;
	new->second[new->second_length]++;
	new->operators[new->depth - 1] = SWAP_S;
	set_score(new);
	return (new);
}

void				add_swaps(t_try *old, t_search *search
								, t_operator last_operator)
{
	t_try			*first_swapped;
	t_try			*second_swapped;

	first_swapped = NULL;
	second_swapped = NULL;
	last_operator = old->depth ? old->operators[old->depth - 1] : NO_OPERATOR;
	if (last_operator > SWAP_S || last_operator == NO_OPERATOR)
	{
		if (old->first_length > 1)
			ft_pq_add(search->pq
						, (first_swapped = create_first_swapped(old)));
		if (old->second_length > 1)
			ft_pq_add(search->pq
						, (second_swapped = create_second_swapped(old)));
		if (old->first_length > 1 && old->second_length > 1)
			ft_pq_add(search->pq, create_both_swapped(old
														, first_swapped
														, second_swapped));
	}
}
