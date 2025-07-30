#include "push_swap.h"

int find_min(t_list *stack)
{
    int min;

    if (!stack)
        return (0);
    min = stack->content;
    while (stack)
    {
        if(stack->content < min)
            min = stack->content;
        stack = stack->next;
    }
    return (min);
}

void    min_to_b(t_list **stack_a, t_list **stack_b)
{
    int min;
	

    if (!stack_a || !*stack_a)
        return ;
    min = find_min(*stack_a);
    while(*stack_a && (*stack_a)->content != min)
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
	return;
}

void print_list(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", stack->content); // changec
        stack = stack->next;
    }
}