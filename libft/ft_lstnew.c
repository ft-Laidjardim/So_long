
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;
	void	*new_content;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_content = content;
	new_node->content = new_content;
	new_node->next = NULL;
	return (new_node);
}
