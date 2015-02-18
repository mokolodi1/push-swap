#include "push_swap.h"

static t_try		*create_push_to_second(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->first_length--;
	new->second_length++;
	new->first = malloc((new->first_length + 1) * sizeof(int));
	new->second = malloc((new->second_length + 1) * sizeof(int));
	ft_memcpy(new->first, old->first + 1, (old->first_length - 1) * sizeof(int));
	ft_memcpy(new->second + 1, old->second, old->second_length * sizeof(int));
	new->second[0] = old->first[0];
	new->first[new->first_length] = 0;
	new->second[new->second_length] = 0;
	new->operators[new->depth - 1] = PUSH_B;
	set_score(new);
	return (new);
}

static t_try		*create_push_to_first(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->first_length++;
	new->second_length--;
	new->first = malloc((new->first_length + 1) * sizeof(int));
	new->second = malloc((new->second_length + 1) * sizeof(int));
	ft_memcpy(new->first + 1, old->first, old->first_length * sizeof(int));
	ft_memcpy(new->second, old->second + 1, (old->second_length - 1) * sizeof(int));
	new->first[0] = old->second[0];
	new->first[new->first_length] = 0;
	new->second[new->second_length] = 0;
	new->operators[new->depth - 1] = PUSH_A;
	set_score(new);
	return (new);
}

void				add_pushes(t_try *old, t_search *search
								, t_operator last_operator)
{
	if (old->first_length
		&& (last_operator != PUSH_A || last_operator == NO_OPERATOR))
		ft_pq_add(search->pq, create_push_to_second(old));
	if (old->second_length
		&& (last_operator != PUSH_B || last_operator == NO_OPERATOR))
		ft_pq_add(search->pq, create_push_to_first(old));
}
