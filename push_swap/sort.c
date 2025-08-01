/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:38:12 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/30 18:17:46 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
		sa(*stack_a);
	if (first > second && second < third && first > third)
		ra(stack_a);
	if (first > second && second > third)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	if (first < second && second > third && first < third)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	if (first < second && second > third && first > third)
		rra(stack_a);
}

static void sort_four_five(t_list **stack_a, t_list **stack_b, int stack_size)
{
    if (stack_size == 4)
    {
        min_to_b(stack_a, stack_b);
        sort_three(stack_a);
        pa(stack_a, stack_b);
    }
    else if (stack_size == 5)
    {
        min_to_b(stack_a, stack_b);
        min_to_b(stack_a, stack_b);
        sort_three(stack_a);
        pa(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
}

static void radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	i;

	find_index(stack_a); // stack_a como t_list**

	i = 0;
	while (!is_ordened(*stack_a))
	{
		len = ft_lstsize(*stack_a);
		while (len--)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (*stack_b)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}

void choose_sort(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_ordened(*stack_a))
		sa(*stack_a);

	else if (stack_size == 3 && !is_ordened(*stack_a))
		sort_three(stack_a);  // ✅ Correto: passa t_list**

	else if ((stack_size == 4 || stack_size == 5) && !is_ordened(*stack_a))
		sort_four_five(stack_a, stack_b, stack_size);  // ✅ t_list** para ambos

	else if (stack_size > 5 && !is_ordened(*stack_a))
		radix_sort(stack_a, stack_b);  // radix_sort ainda espera t_list*
}
