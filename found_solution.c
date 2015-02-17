#include "push_swap.h"

static void			clean_up_priority_queue(t_search *search)
{
	int				i;
	int				count;

	count = 0;
	i = 1;
	while (i <= (int)search->pq->element_count)
	{
		if (((t_try*)search->pq->data[i])->depth >= search->solution_length)
			count++;
		i++;
	}
	printf("(cleanup = %d)", count);
}

void				found_solution(t_try *try, t_search *search)
{
	if (search->solution)
		free(search->solution);
	search->solution = malloc(try->depth * sizeof(t_operator));
	ft_memcpy(search->solution, try->operators
					, try->depth * sizeof(t_operator));
	search->solution_length = try->depth;
	printf("found solution: ");
	print_operators(search->solution_length, search->solution);
	printf(" permutations: %zu ", search->permutation_count);
	clean_up_priority_queue(search);
	printf("\n");
}
