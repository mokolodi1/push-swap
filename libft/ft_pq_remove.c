// header

#include "libft.h"

static void			shrink_array(t_priority_queue *priority_queue)
{
	size_t			byte_size;

	byte_size = priority_queue->element_count * sizeof(void*);
	ft_expand_array(byte_size, byte_size * 2, (void**)&priority_queue->data);
	priority_queue->data_count = priority_queue->element_count * 2;
}

void				*ft_pq_remove(t_priority_queue *priority_queue)
{
	size_t			current;
	size_t			next;
	void			**data;
	void			*to_return;

	if (priority_queue->element_count == 0)
		return (NULL);
	if (priority_queue->element_count < priority_queue->data_count / 4)
		shrink_array(priority_queue);
	data = priority_queue->data;
	to_return = data[0];
	data[0] = data[priority_queue->element_count - 1];
	current = 0;
	while (current < priority_queue->element_count)
	{
		next = priority_queue->compare(data[current], data[next]) > 0
			? current : next;
		if (current == next)
			break ;
		ft_ptrswp(data[current], data[next]);
		current = next;
	}
	priority_queue->element_count--;
	return (to_return);
}
