// header

#include "libft.h"

t_priority_queue		*ft_pq_create_new(int (*compare)(void*, void*))
{
	t_priority_queue	*new;

	new = malloc(sizeof(t_priority_queue));
	new->data_count = T_PQ_DEFAULT_SIZE;
	new->data = malloc(new->data_count * sizeof(void*));
	new->element_count = 0;
	new->compare = compare;
	return (new);
}
