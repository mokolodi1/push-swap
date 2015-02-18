#include "push_swap.h"

static t_try		*create_reverse_rotate_first(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->first = malloc((new->first_length + 1) * sizeof(int));
	ft_memcpy(new->first + 1, old->first, (old->first_length - 1) * sizeof(int));
	new->first[0] = old->first[old->first_length - 1];
	new->first[new->first_length] = 0;
	new->second = old->second;
	new->second[new->second_length]++;
	new->operators[new->depth - 1] = REVERSE_ROTATE_A;
	set_score(new);
	return (new);
}

static t_try		*create_reverse_rotate_second(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->second = malloc((new->second_length + 1) * sizeof(int));
	ft_memcpy(new->second + 1, old->second, (old->second_length - 1) * sizeof(int));
	new->second[0] = old->second[new->second_length - 1];
	new->second[new->second_length] = 0;
	new->first = old->first;
	new->first[new->first_length]++;
	new->operators[new->depth - 1] = REVERSE_ROTATE_B;
	set_score(new);
	return (new);
}

static t_try		*create_reverse_rotate_both(t_try *old
										, t_try *rotated_first
										, t_try *rotated_second)
{
	t_try			*new;

	new = create_general_try(old);
	new->first = rotated_first->first;
	new->second = rotated_second->second;
	new->first[new->first_length]++;
	new->second[new->second_length]++;
	new->operators[new->depth - 1] = REVERSE_ROTATE_A_B;
	set_score(new);
	return (new);
}

void				add_reverse_rotates(t_try *old, t_search *search
										, t_operator last_operator)
{
	t_try			*rotated_first;
	t_try			*rotated_second;

	rotated_first = NULL;
	rotated_second = NULL;
	if (old->first_length > 2
		&& last_operator != ROTATE_A
		&& last_operator != ROTATE_A_B)
		ft_pq_add(search->pq, create_reverse_rotate_first(old));
	if (old->second_length > 2
		&& last_operator != ROTATE_B
		&& last_operator != ROTATE_A_B)
		ft_pq_add(search->pq, create_reverse_rotate_second(old));
	if (rotated_first && rotated_second
		&& last_operator != ROTATE_A
		&& last_operator != ROTATE_B
		&& last_operator != ROTATE_A_B)
		ft_pq_add(search->pq, create_reverse_rotate_both(old, rotated_first
														 , rotated_second));
}
