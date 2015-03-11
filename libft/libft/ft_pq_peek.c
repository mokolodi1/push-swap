/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 00:36:45 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 00:37:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_pq_peek(t_priority_queue *priority_queue)
{
	if (priority_queue->element_count)
		return (priority_queue->data[1]);
	return (NULL);
}
