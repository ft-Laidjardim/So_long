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

void	choose_sort(t_list *stack_a, t_list *stack_b, int stack_size)
{
	(void)stack_b;
	if (stack_size == 2 && !is_ordened(stack_a))
		sa(stack_a);
	if (stack_size == 3 && !is_ordened(stack_a))
		write(1, "Crie a funcao sort_three\n", 25);
	if (stack_size == 4 && !is_ordened(stack_a))
		write(1, "Crie a funcao sort_four\n", 24);
	if (stack_size == 5 && !is_ordened(stack_a))
		write(1, "Crie a funcao sort_five\n", 24);
	if (stack_size == 10 && !is_ordened(stack_a))
		write(1, "Crie a funcao sort_ten\n", 23);
	if (stack_size > 5 && !is_ordened(stack_a))
		write(1, "Crie a funcao sorth_four\n", 25);
}
