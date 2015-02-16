#include "push_swap.h"

static t_try		*create_general_swapped(t_try *old)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = old->first_length;
	new->second_length = old->second_length;
	new->first = malloc(new->first_length * sizeof(int));
	new->second = malloc(new->second_length * sizeof(int));
	ft_memcpy(new->first, old->first, old->first_length * sizeof(int));
	ft_memcpy(new->second, old->second, old->second_length * sizeof(int));
	new->depth = old->depth + 1;
	new->operators = malloc(new->depth * sizeof(t_operator));
	ft_memcpy(new->operators, old->operators, old->depth * sizeof(t_operator));
	return (new);
}

static t_try		*create_first_swapped(t_try *old)
{
	t_try			*new;

	new = create_general_swapped(old);
	ft_intswp(new->first, new->first + 1);
	new->operators[new->depth - 1] = SWAP_A;
	set_score(new);
	return (new);
}

static t_try		*create_second_swapped(t_try *old)
{
	t_try			*new;

	new = create_general_swapped(old);
	ft_intswp(new->second, new->second + 1);
	new->operators[new->depth - 1] = SWAP_B;
	set_score(new);
	return (new);
}

static t_try		*create_both_swapped(t_try *old)
{
	t_try			*new;

	new = create_general_swapped(old);
	ft_intswp(new->first, new->first + 1);
	ft_intswp(new->second, new->second + 1);
	new->operators[new->depth - 1] = SWAP_S;
	set_score(new);
	return (new);
}

void				add_swaps(t_try *old, t_search *search)
{
	t_operator		last_operator;

	last_operator = old->depth ? old->operators[old->depth - 1] : NO_OPERATOR;
	if (last_operator > SWAP_S || last_operator == NO_OPERATOR)
	{
		if (old->first_length > 1)
			ft_pq_add(search->pq, create_first_swapped(old));
		if (old->second_length > 1)
			ft_pq_add(search->pq, create_second_swapped(old));
		if (old->first_length > 1 && old->second_length > 1)
			ft_pq_add(search->pq, create_both_swapped(old));
	}
}
