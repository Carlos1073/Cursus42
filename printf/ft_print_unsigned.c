/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:47:08 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/07 15:18:14 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_nbrlen(size_t nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int nbr)
{
	if (nbr <= UINT_MAX)
	{
		if (nbr >= 10)
		{
			ft_print_unsigned (nbr / 10);
			ft_print_unsigned (nbr % 10);
		}
		else
			ft_print_char(nbr, "0");
	return (ft_nbrlen(nbr));
}
