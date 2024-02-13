#include <stdio.h>
#include "libft.h"

void	f(void *content)
{
	printf("%s\n", (char *)content);
}
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	t_list	*node;
	t_list	*node2;
	t_list	*node3;

	list = 0;
	node2 = ft_lstnew(ft_strdup("Tinky-Winky"));
	node = ft_lstnew(ft_strdup("Dipsy"));
	node3 = ft_lstnew(ft_strdup("LALA"));

	ft_lstadd_back(&list, node);
	ft_lstadd_front(&list, node2);
	ft_lstadd_back(&list, node3);
	printf("Size: %d\n", ft_lstsize(list));
	ft_lstiter(list, f);
	ft_lstdelone(node, &del);
	printf("DESPUES DEL DELONE\n");
	ft_lstiter(list, f);
	printf("LSTMAP:\n");
	ft_lstmap(list, f, del);
	return (0);
}