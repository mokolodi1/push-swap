/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:39:51 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/12 17:44:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int					main(void)
{
	t_priority_queue	*pq;

	pq = ft_pq_create_new((int(*)(void*, void*))ft_strcmp);

	ft_pq_add(pq, ft_strdup("b"));
	ft_pq_add(pq, ft_strdup("g"));
	ft_pq_add(pq, ft_strdup("e"));
	ft_pq_add(pq, ft_strdup("d"));
	ft_pq_add(pq, ft_strdup("a"));
	ft_pq_add(pq, ft_strdup("c"));
	ft_pq_add(pq, ft_strdup("f"));
	ft_pq_add(pq, ft_strdup("g"));

	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	printf("%s", (char*)ft_pq_remove(pq));
	return (0);
}
