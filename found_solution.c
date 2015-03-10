#include "push_swap.h"

void				found_solution(t_try *try, t_search *search)
{
	if (search->solution)
		free(search->solution);
	search->solution = malloc(try->depth * sizeof(t_operator));
	ft_memcpy(search->solution, try->operators
					, try->depth * sizeof(t_operator));
	search->solution_length = try->depth;
}
