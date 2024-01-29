#include <stdio.h>
#include "libft.h"

int main (void)
{
    char const s[] = "lorem ipsum dolor sit amet";
    char const set[] = "te";

    printf("%s \n", s);
    printf("%s", ft_strtrim(s, set));
    return (0);
}