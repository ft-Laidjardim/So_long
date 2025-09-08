
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	chr;

	temp = (char *)s;
	chr = (char)c;
	while (*temp != '\0')
		++temp;
	while (*temp != chr && temp != s)
		--temp;
	if (*temp == chr)
		return (temp);
	return (NULL);
}
