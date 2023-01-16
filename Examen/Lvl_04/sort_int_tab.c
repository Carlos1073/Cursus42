#include <stdlib.h>
#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	while (i < (size -1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

// int main(void)
// {
//     int i = 0;
//     int tab[] = {6, 32, 41, 3, 15, 41, 1, 8};
//     sort_int_tab(tab, 8);
//     while(i < 8)
//     {
//         printf("%d\n", tab[i]);
//         i++;
//     }
// }