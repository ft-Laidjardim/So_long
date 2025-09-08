/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:58 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:26:00 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		len;
	int		i;

	start = 0;
	while (s1[start] != '\0' && ft_inset(s1[start], set) != 0)
		++start;
	len = ft_strlen(s1);
	end = len - 1;
	while (end >= start && ft_inset(s1[end], set) != 0)
		--end;
	ptr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
