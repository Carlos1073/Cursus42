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

#include "libft.h"

static int	check_c(va_list args, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_dec(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hexa(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_check(char const *str, int i, int lenght, va_list args)
{
	int	test;

	test = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			test = check_c(args, str[i + 1]);
			if (test == -1)
				return (-1);
			else
				lenght += test;
			i++;
		}
		else
		{
			lenght += ft_print_char(str[i]);
			if (lenght == -1)
				return (-1);
		}
		i++;
	}
	return (lenght);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		lenght;
	int		i;

	lenght = 0;
	i = 0;
	va_start(args, str);
	lenght = ft_check(str, i, lenght, args);
	va_end(args);
	return (lenght);
}
