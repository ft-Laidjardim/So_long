
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			write (fd, s, 1);
			++s;
		}
	}
}
