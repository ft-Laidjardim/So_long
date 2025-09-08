/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:23:40 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:23:41 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)b;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*str == chr)
			return ((char *)(str));
		++str;
		--n;
	}
	return (NULL);
}
