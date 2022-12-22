/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:50:56 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/22 15:49:49 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void	ft_putnbr(int num)
{
	char	c;
	if (num > 9)
		ft_putnbr(num / 10);
	c = (num % 10) + 48;
	write(1, &c, 1);
}

int	is_prime(int num)
{
	int	i;

	i = 2;
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i;
		int	number;
		int	sum;

		i = 2;
		number = ft_atoi(argv[1]);
		sum = 0;
		if (number <= 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		while (i < number)
		{
			if (is_prime(i))
			{
				sum += i;
			}
			i++;
		}
		if (is_prime(number))
			sum += number;
		ft_putnbr(sum);
		write(1, "\n", 1);	
	}
	else
		write(1, "0\n", 2);
}
