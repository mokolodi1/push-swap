/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_resize_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:23:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/12 17:28:56 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_pq_resize_array(t_priority_queue *priority_queue)
{
	size_t			byte_size;

	byte_size = priority_queue->element_count * sizeof(void*);
	ft_expand_array(byte_size, byte_size * 2, (void**)&priority_queue->data);
	priority_queue->data_count = priority_queue->element_count * 2;
}
