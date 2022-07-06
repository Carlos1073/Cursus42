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

int	ft_putchar(char c, int fd)
{
	if (write(fd, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			if (ft_putchar((num + '0'), 1) == -1)
				return (-1);
		}
		else if (ft_putchar((num - 10 + 'a'), 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_lenght;

	print_lenght = 0;
	print_lenght += write(1, "0x", 2);
	if (print_lenght == -1)
		return (-1);
	if (ptr == 0)
		print_lenght += write(1, "0", 1);
	if (print_lenght == -1)
		return (-1);
	else
	{
		if ((ft_put_ptr(ptr)) == -1)
			return (-1);
		print_lenght += ft_ptr_len(ptr);
		if (print_lenght == -1)
			return (-1);
	}
	return (print_lenght);
}
