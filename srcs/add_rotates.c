/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 13:28:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/13 13:28:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_try		*create_rotated_first(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->first = malloc((new->first_length + 1) * sizeof(int));
	ft_memcpy(new->first, old->first + 1
				, (old->first_length - 1) * sizeof(int));
	new->first[new->first_length - 1] = old->first[0];
	new->first[new->first_length] = 0;
	new->second = old->second;
	new->second[new->second_length]++;
	new->operators[new->depth - 1] = ROTATE_A;
	set_score(new);
	return (new);
}

static t_try		*create_rotated_second(t_try *old)
{
	t_try			*new;

	new = create_general_try(old);
	new->second = malloc((new->second_length + 1) * sizeof(int));
	ft_memcpy(new->second, old->second + 1
				, (old->second_length - 1) * sizeof(int));
	new->second[new->second_length - 1] = old->second[0];
	new->second[new->second_length] = 0;
	new->first = old->first;
	new->first[new->first_length]++;
	new->operators[new->depth - 1] = ROTATE_B;
	set_score(new);
	return (new);
}

static t_try		*create_rotated_both(t_try *old
										, t_try *rotated_first
										, t_try *rotated_second)
{
	t_try			*new;

	new = create_general_try(old);
	new->first = rotated_first->first;
	new->second = rotated_second->second;
	new->first[new->first_length]++;
	new->second[new->second_length]++;
	new->operators[new->depth - 1] = ROTATE_A_B;
	set_score(new);
	return (new);
}

void				add_rotates(t_try *old, t_search *search
								, t_operator last_operator)
{
	t_try			*rotated_first;
	t_try			*rotated_second;

	rotated_first = NULL;
	rotated_second = NULL;
	if (old->first_length > 2
		&& last_operator != REVERSE_ROTATE_A
		&& last_operator != REVERSE_ROTATE_A_B)
		ft_pq_add(search->pq, (rotated_first = create_rotated_first(old)));
	if (old->second_length > 2
		&& last_operator != REVERSE_ROTATE_B
		&& last_operator != REVERSE_ROTATE_A_B)
		ft_pq_add(search->pq, (rotated_second = create_rotated_second(old)));
	if (rotated_first && rotated_second
		&& last_operator != REVERSE_ROTATE_A
		&& last_operator != REVERSE_ROTATE_B
		&& last_operator != REVERSE_ROTATE_A_B)
		ft_pq_add(search->pq, create_rotated_both(old, rotated_first
														, rotated_second));
}
