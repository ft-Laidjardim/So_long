
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	while (len > 0)
	{
		if (*b1 != *b2)
			return (*b1 - *b2);
		++b1;
		++b2;
		--len;
	}
	return (0);
}
