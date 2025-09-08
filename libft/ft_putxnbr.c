/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:24:49 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:24:51 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putxnbr(unsigned int n, char c)
{
	int				count;
	unsigned int	base_len;
	char			*base;

	count = 0;
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		count += ft_putxnbr(n / base_len, c);
		count += ft_putxnbr(n % base_len, c);
	}
	else if (c == 'x')
		count += ft_putchar(base[n]);
	else if (c == 'X')
		count += ft_putchar(ft_toupper(base[n]));
	return (count);
}
