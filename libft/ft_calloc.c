
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	totalsize;
	void	*ptr;

	totalsize = number * size;
	ptr = (void *)malloc(totalsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, totalsize);
	return (ptr);
}
