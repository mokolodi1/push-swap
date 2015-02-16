/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:22:05 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/15 01:00:08 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** make_first_try: numbers has been mallocced in convert_to_indexes
*/

static t_try		*make_first_try(int length, int *numbers)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = length;
	new->second_length = 0;
	new->first = numbers;
	new->second = malloc(new->second_length * sizeof(int));
	new->depth = 0;
	new->operators = malloc(new->depth);
	set_score(new);
	return (new);
}

static void			setup_search(t_search *search, int length)
{
	int				i;

	ft_bzero(search, sizeof(t_search));
	search->pq = ft_pq_create_new((int (*)(void*, void*))&compare_tries);
	search->ascending_numbers = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		search->ascending_numbers[i] = i;
		i++;
	}
}

static int			index_of(int needle, int *haystack)
{
	int				index;

	index = 0;
	while (haystack[index] != needle)
		index++;
	return (index);
}

void				convert_to_indexes(int length, int **numbers)
{
	int				sorted[length];
	int				*wanted;
	int				i;

	ft_memcpy(sorted, *numbers, length * sizeof(int));
	ft_quicksort(length, sorted);
	wanted = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		wanted[index_of(sorted[i], *numbers)] = i;
		i++;
	}
	ft_ptrswp((void**)&wanted, (void**)numbers);
	/* *numbers = [5, 1, 4, 3]; */
	/* sorted = [1, 3, 4, 5]; */
	/* wanted = [3, 0, 2, 1] */
}

void				print_debugging(t_search *search)
{
	printf("\nsearch->permutation_count = %zu\n", search->permutation_count);
	printf("search->pq->element_count = %zu\n", search->pq->element_count);
	printf("search->solution = %p\n", search->solution);
	for (int i = 1; i <= (int)search->pq->element_count; i++)
	{
		printf("search->pq->data[%d] = ", i);
		print_try((t_try*)(search->pq->data[i]));
	}
}

void				handle_push_swap(int length, int *numbers)
{
	t_search		search;

	setup_search(&search, length);
	convert_to_indexes(length, &numbers);
	ft_pq_add(search.pq, make_first_try(length, numbers));

	while (!search.solution)
	{
		permutate(&search);
		//print_debugging(&search);
		if (search.permutation_count % 10000 == 0)
			printf("search->permutation_count = %zu\tsearch->pq->element_count = %zu\n"
				   , search.permutation_count, search.pq->element_count);
	}
	printf("\ndone\n");
	print_operators(search.solution_length, search.solution);
	//ft_putchar('\n');
	printf("\n");
}
