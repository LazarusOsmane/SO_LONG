#include "libft.h"

void    *ft_malloc(int size, int len)
{
    void    *p;

    p = malloc(size * len);
    if (!p)
        return (NULL);
    return (p);
}
