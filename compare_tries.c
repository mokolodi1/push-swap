#include "push_swap.h"

int					compare_tries(t_try *first, t_try *second)
{
	return (second->score - first->score);
}
