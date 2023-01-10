#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
	int size = end - start+1;
	int *ptr;
	int i = 0;
	if (size)
	{
		ptr = (int*) malloc(sizeof(int) * size);
		while(start<=end)
		{
			ptr[i] =end;
			i++;
			end--;
		}
		return ptr;
	}
return (NULL);
}

int	main(void)
{
	int	i;
	int	check;
	int	*ptr;
	int	start = 1;
	int	end = 3;

	i = -1;
	check = 0;
	ptr = ft_rrange(start, end);
	while (ptr[++i] <= end)
	{
		if (check == 1 && ptr[i] == 0)
			break;
		if (check == 0 && ptr[i] == 0)
			check++;

		printf("%d\n", ptr[i]);
	}
	return (0);
}