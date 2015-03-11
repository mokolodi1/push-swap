/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_resize_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:23:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/11 17:10:53 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_pq_resize_array(t_priority_queue *priority_queue)
{
	size_t			old_size;
	size_t			new_size;

	old_size = priority_queue->element_count + 1;
	new_size = priority_queue->element_count * 2 + 1;
	ft_array_expand(old_size * sizeof(void*), new_size * sizeof(void*)
					, (void**)&priority_queue->data);
	priority_queue->data_count = new_size - 1;
}
