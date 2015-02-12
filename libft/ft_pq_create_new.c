/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pq_create_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:50 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/12 17:22:12 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_priority_queue		*ft_pq_create_new(int (*compare)(void*, void*))
{
	t_priority_queue	*new;

	new = malloc(sizeof(t_priority_queue));
	new->data_count = 4;
	new->data = malloc(new->data_count * sizeof(void*));
	new->element_count = 0;
	new->compare = compare;
	return (new);
}
