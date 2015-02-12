// header

#include "libft.h"

void				ft_expand_array(size_t bytes_before, size_t bytes_after
									, void **data)
{
	void			*new;

	new = malloc(bytes_after);
	ft_memcmp(new, *data, bytes_before);
	free(data);
	*data = new;
}
