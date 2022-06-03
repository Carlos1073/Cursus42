#include "lib_printf.h"

static int	check_c(va_list ptr, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(ptr, char *)));
//	else if (c == 'p')
//		return (ft_print_ptr(va_arg(ptr, void *)));
//	else if (c == 'd')
//		
//	else if (c == 'i')
//		
//	else if (c == 'u')
//	
	else if (c == 'x')
		return (ft_print_hexa(va_arg(ptr, unsigned long)));
	else if (c == 'X')
		return (ft_print_hexaupper(va_arg(ptr, unsigned long)));
	else if (c == '%')
	{
		write (1, "%", 1);
		return (1);
	}
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

int	main(void)
{
	printf("Hello %c %s %x %X World!\n", 'd', "damn", 3456, 3456);
	ft_printf("Hello %c %s %x %X World!\n", 'd', "damn", 3456, 3456);
	return (0);	
}

