#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int *ptr;
    int i;
    int len;

    i = 0;
    len = end - start;
    if (start > end)
        return (ft_rrange(end, start));
    ptr = malloc(sizeof(int) * len);
    if (ptr)
    {
        while (i < len)
        {
            ptr[i] = start;
            start++;
            i++;
        }
    }
    return (ptr);
}