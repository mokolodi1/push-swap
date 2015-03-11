/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:09:42 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 23:13:05 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_pq_add(t_priority_queue *priority_queue, void *element)
{
	size_t			current;
	size_t			next;
	void			**data;

	if (priority_queue->element_count + 1 > priority_queue->data_count)
		ft_pq_resize_array(priority_queue);
	data = priority_queue->data;
	current = priority_queue->element_count + 1;
	data[current] = element;
	while (current > 1)
	{
		next = current / 2;
		if (priority_queue->compare(data[current], data[next]) > 0)
			ft_ptrswp(&data[current], &data[next]);
		else
			break ;
		current = next;
	}
	priority_queue->element_count++;
}
