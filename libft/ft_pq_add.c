// header

#include "libft.h"

static void			expand_array(t_priority_queue *priority_queue)
{
	size_t			byte_size;

	byte_size = priority_queue->element_count * sizeof(void*);
	ft_expand_array(byte_size, byte_size * 2, (void**)&priority_queue->data);
	priority_queue->data_count = priority_queue->element_count * 2;
}

void				ft_pq_add(t_priority_queue *priority_queue, void *element)
{
	size_t			current;
	size_t			next;
	void			**data;

	if (priority_queue->element_count + 1 > priority_queue->data_count)
		expand_array(priority_queue);
	data = priority_queue->data;
	data[priority_queue->element_count] = element;
	current = priority_queue->element_count;
	while (current > 0)
	{
		next = current / 2;
		if (priority_queue->compare(data[current], data[next]) > 0)
			ft_ptrswp(data + current, data + next);
		current = next;
	}
	priority_queue->element_count++;
}
