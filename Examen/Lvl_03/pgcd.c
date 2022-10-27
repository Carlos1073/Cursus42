/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:57:10 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/27 15:38:13 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, const char *argv[])
{
	int	nbr1;
	int	nbr2;

	nbr1 = atoi(argv[1]);
	nbr2 = atoi(argv[2]);
	if (argc == 3)
	{
		if (nbr1 > 0 && nbr2 > 0)
		{
			while (nbr1 != nbr2)
			{
				if (nbr1 > nbr2)
					nbr1 -= nbr2;
				else
					nbr2 -= nbr1;
			}
		printf("%d\n", nbr1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

// void	pgcd(int a, int b)
// {
// 	int	div;
// 	int	pgcd;

// 	div = 1;
// 	if (a <= 0 || b  <= 0)
// 		return ;
// 	while (div <= a || div <= b)
// 	{
// 		if (a % div == 0 && b % div == 0)
// 			pgcd = div;
// 		div++;
// 	}
// 	printf("%d", pgcd);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 		pgcd(atoi(argv[1]), atoi(argv[2]));
// 	printf("\n");
// 	return (0);
// }
