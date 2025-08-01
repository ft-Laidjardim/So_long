/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:47:55 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/30 18:17:57 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * n);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0' || str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	correct_input(char **str, int count)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < count)
	{
		if (!is_valid(str[i]) || ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
			return (0);
		i++;
	}
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;
	stack_a = NULL;
	stack_b = NULL;
	stack_size = argc -1;
	argv++;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[0]);
		if (!argv)
			ft_error(NULL, NULL, NULL, 0);
		stack_size = 0;
		while (argv[stack_size])
			stack_size++;
	}
	if (!correct_input(argv, stack_size))
		ft_error(argv, NULL, NULL, argc);
	stack_a = fill_list(argv, stack_size, argc);
	choose_sort(&stack_a, &stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
	if (argc == 2)
		free_split(argv);
	return (0);
}
