/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:14:04 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/30 18:13:20 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (!stack_a || !*stack_a)
		return ;
	min = find_min(*stack_a);
	if (ft_lstsize(*stack_a) == 5
		&& ((*stack_a)->next->next->next->content == min
			|| (*stack_a)->next->next->next->next->content == min))
	{
		while (*stack_a && (*stack_a)->content != min)
			rra(stack_a);
	}
	else
		while (*stack_a && (*stack_a)->content != min)
			ra(stack_a);
	if (*stack_a)
		pb(stack_b, stack_a);
}

void	find_index(t_list **stack_a)
{
	t_list	*i;
	t_list	*j;
	int		count;

	i = *stack_a;
	while (i)
	{
		count = 0;
		j = *stack_a;
		while (j)
		{
			if (i->content > j->content)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
	return ;
}

