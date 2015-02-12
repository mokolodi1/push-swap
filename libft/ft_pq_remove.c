/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:25 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/12 18:05:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_pq_remove(t_priority_queue *priority_queue)
{
	size_t			current;
	size_t			next;
	void			**data;
	void			*to_return;

	if (priority_queue->element_count == 0)
		return (NULL);
	if (priority_queue->element_count - 1 < priority_queue->data_count / 4)
		ft_pq_resize_array(priority_queue);
	data = priority_queue->data;
	to_return = data[0];
	data[0] = data[priority_queue->element_count - 1];
	current = 1;
	while (current < priority_queue->element_count)
	{
		next = current * 2;
		if (priority_queue->compare(data[next - 1], data[next]) > 0)
			next++;
		ft_ptrswp(data[current - 1], data[next - 1]);
		current = next;
	}
	priority_queue->element_count--;
	return (to_return);
}
