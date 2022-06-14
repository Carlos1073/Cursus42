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

#include "../include/ft_printf.h"

int	ft_print_hexa(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_print_hexa(nbr / 16);
		len += ft_print_hexa(nbr % 16);
	}
	else
		len += write(1, &"0123456789abcdef"[nbr], 1);
	return (len);
}
