/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:38:12 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/23 13:12:11 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->content;
	second = stack_a->next->content;
	third = stack_a->next->next->content;
	if (first > second && second < third && first < third)
		sa(stack_a);
	if (first > second && second < third && first > third)
		ra(&stack_a);
	if (first > second && second > third)
	{
		sa(stack_a);
		rra(&stack_a);
	}
	if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(&stack_a);
	}
	if (first < second && second > third && first > third)
		rra(&stack_a);
}

static void	sort_four_five(t_list *stack_a, t_list *stack_b, int stack_size)
{
	if (stack_size == 4)
	{
		min_to_b(&stack_a, &stack_b);
		sort_three(stack_a);
		pa(&stack_a, &stack_b);
	}
	else if(stack_size == 5)
	{
		min_to_b(&stack_a, &stack_b);
		min_to_b(&stack_a, &stack_b);
		sort_three(stack_a);
		print_list(stack_a);
		pa(&stack_a, &stack_b);
		print_list(stack_b);
		pa(&stack_a, &stack_b);
	}
}

void	choose_sort(t_list *stack_a, t_list *stack_b, int stack_size)
{
	(void)stack_b;
	if (stack_size == 2 && !is_ordened(stack_a))
		sa(stack_a);
	if (stack_size == 3 && !is_ordened(stack_a))
		sort_three(stack_a);
	if ((stack_size == 4 || stack_size == 5 )&& !is_ordened(stack_a))
		sort_four_five(stack_a, stack_b, stack_size);
	if (stack_size == 10 && !is_ordened(stack_a))
		write(1, "Crie a funcao sort_ten\n", 23);
	if (stack_size > 5 && !is_ordened(stack_a))
		write(1, "Crie a funcao sorth_four\n", 25);
}
