/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:48:19 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/23 12:25:07 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_src, t_list **stack_dest)
{
	t_list	*temp;

	if (!stack_src || !*stack_src)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dest;
	*stack_dest = temp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
