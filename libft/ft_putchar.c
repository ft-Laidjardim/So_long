
#include "libft.h"

int	ft_putchar(int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	write(1, &chr, 1);
	return (1);
}
