#include <stdio.h>
#include "libft.h"

void	f(void *content)
{
	printf("%s\n", (char *)content);
}

void	f2(unsigned int i, char	*s)
{
	if(ft_isalpha((int)*s))
		*s -= 32;
}

void	*f3(void *content)
{
	ft_striteri((char *)content,f2);
	return (content);
}

void	*ft_map(void *ct)
{
	int i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	t_list	*list2;
	t_list	*node;
	t_list	*node2;
	t_list	*node3;

	list = 0;
	node2 = ft_lstnew(ft_strdup("Tonky-Wonky"));
	node = ft_lstnew(ft_strdup("Dopsy"));
	node3 = ft_lstnew(ft_strdup("Lolo"));

	ft_lstadd_back(&list, node);
	ft_lstadd_front(&list, node2);
	ft_lstadd_back(&list, node3);
	printf("Size: %d\n", ft_lstsize(list));
	ft_lstiter(list, f);
	ft_lstclear(&node2, &del);
	printf("DESPUES DEL clear\n");
	ft_lstiter(list, f);
	printf("LSTMAP:\n");
	list2 = ft_lstmap(list,f3, del);
	ft_lstiter(list2, f);
	return (0);
}
