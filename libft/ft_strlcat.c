/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:26 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:25:28 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (size + srclen);
	while ((*dst != '\0') && (size - 1 > 0))
	{
		++dst;
		--size;
	}
	while ((*src != '\0') && (size - 1 > 0))
	{
		*dst = *src;
		++dst;
		++src;
		--size;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
