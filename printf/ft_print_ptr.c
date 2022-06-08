/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:30:24 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/07 15:35:42 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	nbr;
	int	len;

 	len = 0;
	if (!str = NULL)
	{
		nbr = (unsigned long long)ptr;
		len += write(1, "0x", 2);
		len += ft_print_hexa(nbr);
		return (len);
	}
	else
		len =+ write(1, "0x0", 3);
	return (len);
}
