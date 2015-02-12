/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:09:42 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/12 18:05:35 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_pq_add(t_priority_queue *priority_queue, void *element)
{
	size_t			current;
	size_t			next;
	void			**data;

	if (priority_queue->element_count > priority_queue->data_count)
		ft_pq_resize_array(priority_queue);
	data = priority_queue->data;
	data[priority_queue->element_count] = element;
	current = priority_queue->element_count;
	while (current > 0)
	{
		next = current / 2;
		if (priority_queue->compare(data[current], data[next]) > 0)
			ft_ptrswp(data + current, data + next);
		current = next;
	}
	priority_queue->element_count++;
}
