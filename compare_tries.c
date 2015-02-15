// header

#include "push_swap.h"

int					compare_tries(t_try *first, t_try *second)
{
	return (first->score - second->score);
}
