/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:35:36 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/13 12:35:10 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	check_c(va_list ptr, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(ptr, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(ptr, unsigned long long)));
	else if (c == 'd')
		return (ft_print_dec(va_arg(ptr, int)));
	else if (c == 'i')
		return (ft_print_dec(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_print_hexa(va_arg(ptr, unsigned int)));
	else if (c == 'X')
		return (ft_print_hexaupper(va_arg(ptr, unsigned int)));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	ptr;
	int		lenght;
	int		i;

	lenght = 0;
	i = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lenght += check_c(ptr, str[i + 1]);
			i++;
		}
		else
			lenght += ft_print_char(str[i]);
		i++;
	}
	va_end(ptr);
	return (lenght);
}
