/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:04 by caguerre          #+#    #+#             */
/*   Updated: 2023/04/25 11:52:02 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	print_string(char *str, int *lenght)
{
	if (!str)
		str = "(null)";
	while (*str)
		*lenght += write(1, str++, 1);
}

void	print_number(long long int num, int base, int *lenght)
{
	char	*number = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		*lenght += write(1, "-", 1);
	}
	if (num >= base)
		print_number((num / base), base, lenght);
	*lenght += write(1, &number[num % base], 1);
}

int  ft_printf(const char *format, ...)
{
	int		lenght = 0;
	
	va_list pointer;
	va_start(pointer, format);
	
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				print_string(va_arg(pointer, char *), &lenght);
			else if (*format == 'd')
				print_number(va_arg(pointer, int), 10, &lenght);
			else if (*format == 'x')
				print_number(va_arg(pointer, unsigned int), 16, &lenght);
		}
		else
			lenght += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), lenght);
}
