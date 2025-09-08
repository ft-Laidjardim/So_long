/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:53 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:25:55 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	chr;

	temp = (char *)s;
	chr = (char)c;
	while (*temp != '\0')
		++temp;
	while (*temp != chr && temp != s)
		--temp;
	if (*temp == chr)
		return (temp);
	return (NULL);
}
