/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:16:24 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/28 14:49:03 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *nbr)
{
	int	i;
	int	res;

	i = 0;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = res * 10 + (nbr[i] - 48);
		i++;
	}	
	return (res);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	ft_tab_mult(char *str)
{
	int	number;
	int	res;
	int	i;

	number = ft_atoi(str);	
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " * ", 3);
		ft_putnbr(number);
		write(1, " = ", 3);
		ft_putnbr(i * number);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}


