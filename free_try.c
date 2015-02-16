#include "push_swap.h"

void				free_try(t_try *try)
{
	free(try->first);
	free(try->second);
	free(try->operators);
	free(try);
}
