/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:38:32 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/27 16:35:49 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	print_hex(int nbr)
{
	char hex[] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &hex[nbr % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}

// int	ft_atoi(char *nbr)
// {
// 	int	result;

// 	result = 0;
// 	while (*nbr >= '0' && *nbr <= '9')
// 	{
// 		result = result * 10 + (*nbr - 48);
// 		nbr++;
// 	}
// 	return (result);
// }

// void	print_hex(int nbr)
// {
// 	if (nbr >= 16)
// 		print_hex(nbr / 16);	
// 	write(1, &"0123456789abcdef"[nbr % 16], 1);
// }

// int	main(int argc, char **argv)
// {
// 	int	nbr;
	
// 	if (argc == 2)
// 	{
// 		nbr = ft_atoi(argv[1]);
// 		print_hex(nbr);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }
