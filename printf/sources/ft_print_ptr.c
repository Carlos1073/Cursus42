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

static int	ft_putchar(char c)
{
	if (write(1, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}

static int	ft_hexaux(size_t nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_hexaux(nb / 16, base);
	if (count == -1)
		return (-1);
	count += ft_putchar((char)(base[nb % 16]));
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	if (count == -1)
		return (-1);
	count += ft_hexaux((size_t)ptr, "0123456789abcdef");
	if (count == -1)
		return (-1);
	return (count);
}
