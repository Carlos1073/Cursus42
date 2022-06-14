/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:30:24 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/09 14:33:28 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_ptrlen(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static void	ft_ptrcon(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_ptrcon(nbr / 16);
		ft_ptrcon(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long nbr)
{
	int		len;

	len = 0;
	write(1, "0x", 2);
	if (nbr == 0)
		return (write(1, "0", 1) + 2);
	else
		ft_ptrcon(nbr);
	return (ft_ptrlen(nbr) + 2);
}
