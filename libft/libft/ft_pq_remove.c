/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:25 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 17:31:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			setup(t_priority_queue *priority_queue, void ***data
									, size_t *current, void **to_return)
{
	if (priority_queue->element_count - 1 < priority_queue->data_count / 4)
		ft_pq_resize_array(priority_queue);
	*data = priority_queue->data;
	*current = 1;
	*to_return = (*data)[*current];
	(*data)[*current] = (*data)[priority_queue->element_count];
}

void				*ft_pq_remove(t_priority_queue *priority_queue)
{
	void			**data;
	size_t			current;
	size_t			next;
	void			*to_return;

	if (priority_queue->element_count == 0)
		return (NULL);
	setup(priority_queue, &data, &current, &to_return);
	while (current < priority_queue->element_count / 2)
	{
		next = current * 2;
		if (priority_queue->compare(data[next], data[next + 1]) < 0)
			next++;
		if (priority_queue->compare(data[current], data[next]) < 0)
			ft_ptrswp(&data[current], &data[next]);
		else
			break ;
		current = next;
	}
	if (current * 2 + 1 == priority_queue->element_count
		&& priority_queue->compare(data[current], data[current * 2]) < 0)
		ft_ptrswp(&data[current], &data[current * 2]);
	priority_queue->element_count--;
	return (to_return);
}
