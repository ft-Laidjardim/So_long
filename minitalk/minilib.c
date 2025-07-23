
static void	putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	putnbr(int n)
{
	if (n > 9)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_printf(char *str)
{
	if (str[0] == '%')
		putnbr(&str[2]);
	else
		putstr(str);
	return (0);
}