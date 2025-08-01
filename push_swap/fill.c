/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:49:39 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/30 18:19:16 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_newnode(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = value;
	new_node->next = NULL;
	return (new_node);
}

static t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

t_list	*fill_list(char **argv, int count, int argc)
{
	int		i;
	long	num;
	t_list	*stack;
	t_list	*new_node;

	i = 0;
	num = 0;
	stack = NULL;
	while (i < count)
	{
		num = ft_atol(argv[i]);
		new_node = ft_newnode(num);
		if (!new_node)
		{
			ft_error(argv, stack, NULL, argc);
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}
