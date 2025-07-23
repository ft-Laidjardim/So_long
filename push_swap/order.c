/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:30:09 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/23 12:27:51 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordened(t_list *stack)
{
	t_list	*iter;

	while (stack)
	{
		iter = stack->next;
		if (iter && iter->content < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
