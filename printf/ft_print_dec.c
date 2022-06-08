/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:19:11 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/07 12:21:22 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_dec(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_print_dec(nbr / 10);
		len += ft_print_dec(nbr % 10);
	}
	else
		len += write(1, &"0123456789abcdef"[nbr], 1);
	return (len);
}
