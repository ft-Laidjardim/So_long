/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:31 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:25:33 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*srcptr;
	size_t		srclen;
	size_t		i;

	srcptr = src;
	srclen = 0;
	while (*srcptr != '\0')
	{
		++srcptr;
		++srclen;
	}
	i = dstsize;
	if (dstsize > 0)
	{
		while ((i - 1 > 0) && (*src != '\0'))
		{
			*dst = *src;
			++dst;
			++src;
			--i;
		}
		*dst = '\0';
	}
	return (srclen);
}
