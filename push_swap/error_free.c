/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:48 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/30 18:18:42 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **args, t_list *a, t_list *b, int argc)
{
	write(2, "Error\n", 6);
	if (argc == 2)
		free_split(args);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

