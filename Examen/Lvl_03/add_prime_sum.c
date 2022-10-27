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
	int	negative;
	
	i = 0;
	res = 0;
	negative = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	i = 0;
	if (str[i] == '-')
		negative = -1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * negative);
}

void	ft_putnbr(int num)
{
	char	c;
	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + 48;
	write(1, &c, 1);
}

int	is_prime(int num)
{
	int	i;

	i = 3;
	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return (0);
		i += 2;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	int	number;
	int	sum;
	
	sum = 0;
	number = ft_atoi(argv[1]);
	if (argc == 2)
	{
		while (number > 0)
			if (is_prime(number--))
				sum += (number + 1);
		ft_putnbr(sum);
	}
	if (argc != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
