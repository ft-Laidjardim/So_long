
#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	char	*p;
	size_t	i;

	p = b;
	i = 0;
	while (i < len)
	{
		p[i] = 0;
		++i;
	}
}
