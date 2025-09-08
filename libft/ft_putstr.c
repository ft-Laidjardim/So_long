
#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (ft_putstr("(null)"));
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], sizeof(char));
		i++;
	}
	return (i);
}
