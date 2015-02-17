#include "push_swap.h"

static t_try		*create_reverse_rotate_first(t_try *old)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = old->first_length;
	new->second_length = old->second_length;
	new->first = malloc(new->first_length * sizeof(int));
	new->second = malloc(new->second_length * sizeof(int));
	ft_memcpy(new->first + 1, old->first, (old->first_length - 1) * sizeof(int));
	ft_memcpy(new->second, old->second, old->second_length * sizeof(int));
	new->first[0] = old->first[old->first_length - 1];
	new->depth = old->depth + 1;
	new->operators = malloc(new->depth * sizeof(t_operator));
	ft_memcpy(new->operators, old->operators, old->depth * sizeof(t_operator));
	new->operators[new->depth - 1] = REVERSE_ROTATE_A;
	set_score(new);
	return (new);
}

static t_try		*create_reverse_rotate_second(t_try *old)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = old->first_length;
	new->second_length = old->second_length;
	new->first = malloc(new->first_length * sizeof(int));
	new->second = malloc(new->second_length * sizeof(int));
	ft_memcpy(new->first, old->first, old->first_length * sizeof(int));
	ft_memcpy(new->second + 1, old->second, (old->second_length - 1) * sizeof(int));
	new->second[0] = old->second[old->second_length - 1];
	new->depth = old->depth + 1;
	new->operators = malloc(new->depth * sizeof(t_operator));
	ft_memcpy(new->operators, old->operators, old->depth * sizeof(t_operator));
	new->operators[new->depth - 1] = REVERSE_ROTATE_B;
	set_score(new);
	return (new);
}

static t_try		*create_reverse_rotate_both(t_try *old)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = old->first_length;
	new->second_length = old->second_length;
	new->first = malloc(new->first_length * sizeof(int));
	new->second = malloc(new->second_length * sizeof(int));
	ft_memcpy(new->first + 1, old->first, (old->first_length - 1) * sizeof(int));
	ft_memcpy(new->second + 1, old->second, (old->second_length - 1) * sizeof(int));
	new->first[0] = old->first[old->first_length - 1];
	new->second[0] = old->second[old->second_length - 1];
	new->depth = old->depth + 1;
	new->operators = malloc(new->depth * sizeof(t_operator));
	ft_memcpy(new->operators, old->operators, old->depth * sizeof(t_operator));
	new->operators[new->depth - 1] = REVERSE_ROTATE_A_B;
	set_score(new);
	return (new);
}

void				add_reverse_rotates(t_try *old, t_search *search)
{
	t_operator		last_operator;

	last_operator = old->depth ? old->operators[old->depth - 1] : 0;
	if (old->first_length > 2
		&& last_operator != ROTATE_A
		&& last_operator != ROTATE_A_B)
		ft_pq_add(search->pq, create_reverse_rotate_first(old));
	if (old->second_length > 2
		&& last_operator != ROTATE_B
		&& last_operator != ROTATE_A_B)
		ft_pq_add(search->pq, create_reverse_rotate_second(old));
	if (old->first_length > 2 && old->second_length > 2
		&& last_operator != ROTATE_A
		&& last_operator != ROTATE_B
		&& last_operator != ROTATE_A_B)
		ft_pq_add(search->pq, create_reverse_rotate_both(old));
}
