/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:23:54 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:23:55 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
	{
		ft_memcpy(cdst, csrc, len);
		return (cdst);
	}
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			cdst[len] = csrc[len];
		}
	}
	return (cdst);
}
