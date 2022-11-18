/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:23:52 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/09 14:18:49 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}

static int	ft_putnbrbase(unsigned long long nbr, char *base)
{
	int	char_count;

	char_count = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		if (ft_putchar('-') == -1)
			return (-1);
		char_count++;
	}
	if (nbr > (unsigned long long)ft_strlen(base) - 1)
		char_count += ft_putnbrbase(nbr / ft_strlen(base), base);
	if (char_count == -1)
		return (-1);
	if (ft_putchar(base[nbr % ft_strlen(base)]) == -1)
		return (-1);
	char_count++;
	return (char_count);
}

int	ft_print_hexa(unsigned long int nbr, char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i] != '\0')
	{
		j = 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[i + j] != '\0')
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
	}
	if (i <= 1)
		return (0);
	return (ft_putnbrbase(nbr, base));
}
