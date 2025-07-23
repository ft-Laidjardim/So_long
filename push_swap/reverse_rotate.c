/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:32:42 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/23 12:36:10 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*temp;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	first = *stack;
	while (first->next)
		first = first->next;
	before_last = *stack;
	while (before_last && before_last->next->next)
		before_last = before_last->next;
	*stack = first;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
