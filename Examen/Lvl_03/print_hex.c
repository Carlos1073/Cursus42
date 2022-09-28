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

int	ft_atoi(char *nbr)
{
	int	result;

	result = 0;
	while (*nbr >= '0' && *nbr <= '9')
	{
		result = result * 10 + (*nbr - 48);
		nbr++;
	}
	return (result);
}

void	print_hex(int nbr)
{
	if (nbr >= 16)
		print_hex(nbr / 16);	
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

int	main(int argc, char **argv)
{
	int	nbr;
	
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		print_hex(nbr);
	}
	write(1, "\n", 1);
	return (0);
}
