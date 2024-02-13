#include "libft.h"
#include <stdio.h>
int	main(void)
{
		const char *str1 = "Hello,World,Split,Me";
	ft_split(str1, ',');

	const char *str2 = "Lorem ipsum dolor sit amet";
	ft_split(str2, ' ');

	const char *str3 = "apple,banana,cherry,orange";
	ft_split(str3, ',');

	ft_split("hello!",' ');

	return (0);
}