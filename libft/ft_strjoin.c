/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:22 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:25:23 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		res[i] = s1[i];
		++i;
	}
	i = 0;
	while (i < l2)
	{
		res[l1 + i] = s2[i];
		++i;
	}
	res[l1 + i] = '\0';
	return (res);
}
