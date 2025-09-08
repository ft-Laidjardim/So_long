/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:21:44 by ljessica          #+#    #+#             */
/*   Updated: 2025/09/08 15:21:46 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	totalsize;
	void	*ptr;

	totalsize = number * size;
	ptr = (void *)malloc(totalsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, totalsize);
	return (ptr);
}
