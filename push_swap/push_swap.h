/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:19:26 by ljessica          #+#    #+#             */
/*   Updated: 2025/07/30 18:13:33 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

// utility functions
long	ft_atol(char *str);
int		is_valid(char *str);
int		correct_input(char **str, int count);
int		is_ordened(t_list *stack);
int		ft_lstsize(t_list *lst);

// movement functions
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);

// free funtions
void	free_split(char **split);
void	free_stack(t_list *stack);


// errors
void	ft_error(char **args, t_list *a, t_list *b, int argc);
void	dummy_del(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));



// main
int		main(int argc, char **argv);

// parce and stacks
t_list	*fill_list(char **argv, int count, int argc);
char	**ft_split(char *str);
void	find_index(t_list **stack_a);

// sorting
void choose_sort(t_list **stack_a, t_list **stack_b, int stack_size);
int		find_min(t_list *stack);
void	min_to_b(t_list **stack_a, t_list **stack_b);
void	print_list(t_list *stack);
#endif