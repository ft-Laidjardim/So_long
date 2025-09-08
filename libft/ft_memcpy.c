
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	cdst = (char *)dst;
	csrc = (const char *)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		++i;
	}
	return (dst);
}
