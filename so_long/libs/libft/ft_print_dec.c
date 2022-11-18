/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:45 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/23 12:43:36 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}

int	ft_print_dec(int nbr)
{
	int						printed;
	unsigned long long int	number;

	printed = 0;
	number = nbr;
	if (nbr < 0)
	{
		number = -number;
		printed += ft_putchar('-');
		if (printed == -1)
			return (-1);
	}
	if (number >= 10)
	{
		printed += ft_print_dec(number / 10);
		if (printed == -1)
			return (-1);
		printed += ft_print_dec(number % 10);
	}
	else
		printed += ft_putchar(number + '0');
	if (printed == -1)
		return (-1);
	return (printed);
}
