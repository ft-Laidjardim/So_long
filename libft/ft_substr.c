/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:26:03 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:26:04 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	diff;
	char	*sub;
	char	*temp;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	diff = s_len - start;
	if (len > diff)
		len = diff;
	sub = (char *)malloc((sizeof(char) * (len)) + 1);
	if (sub == NULL)
		return (NULL);
	temp = (char *)s + start;
	ft_strlcpy(sub, temp, len + 1);
	return (sub);
}
