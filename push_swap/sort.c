/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:38:12 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/23 12:43:20 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_list *stack_a, t_list *stack_b, int stack_size)
{
	(void)stack_b;
	if (stack_size == 2 && !is_ordened(stack_a))
	{
		sa(stack_a);
	}
}
