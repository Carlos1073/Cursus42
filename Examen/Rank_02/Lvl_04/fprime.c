#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc == 2)
	{
		i = 1;
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
		while (number >= ++i)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				if (number == i)
					break ;
				printf("*");
				number /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}

// 	int nbr = atoi(argv[1]);
// 	int i = 2;
// 	int flag = 0;

// 	if (nbr == 1)
// 		{
// 			write(1, "1\n", 2);
// 			return (0);
// 		}
// 	while (i <= nbr)
// 	{
// 		if (i == nbr)
// 		{
// 			if (flag > 0)
// 				printf("*");
// 			printf("%d", i);
// 			// if (flag == 0)
// 			// 	printf(" es numero primo \n");
// 			break;
// 		}
// 		if (nbr % i == 0)
// 		{
// 			if (flag > 0)
// 				printf("*");	
// 			printf("%d", i);
// 			nbr /= i;
// 			flag++;
// 			continue;
// 		}
// 		i++;
// 	}
// 	return (0);
// }