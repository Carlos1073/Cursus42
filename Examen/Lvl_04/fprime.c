#include <stdlib.h>
#include <stdio.h>

// int main(int argc, char **argv)
// {
//     int i;
//     int nbr;

//     nbr = atoi(argv[1]);
//     i = 2;
//     if (argc == 2)
//     {
//         if (nbr == 1)
//             printf("1");
//         while (i <= nbr)
//         {
//             if (nbr % i == 0)
//             {
//                 prntf("%d", i);
//                 if (nbr == i)
//                     break ;
//                 printf("*");
//                 nbr = nbr / i;
//                 i = 2;
//             }
//             i++;
//         }

//     }
//     printf("\n");
// }

int main(int argc, char **argv)
{
	int nbr = atoi(argv[1]);
	int i = 2;
	int flag = 0;

	while (i <= nbr)
	{
		if (i == nbr)
		{
			if (flag > 0)
				printf("*");
			printf("%d", i);
			// if (flag == 0)
			// 	printf(" es numero primo \n");
			break;
		}
		if (nbr % i == 0)
		{
			if (flag > 0)
				printf("*");	
			printf("%d", i);
			nbr /= i;
			flag++;
			continue;
		}
		i++;
	}
	return (0);
}