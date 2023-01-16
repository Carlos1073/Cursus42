#include <unistd.h>
#include <stdio.h>
#include <libc.h>

int	ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	base(int c, int base)
{
	char *str1 = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int	i;

	i = 0;
	while (i < base)
	{
		if (c == str1[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	number;
	int	negative;
	int	i;

	number = 0;
	negative = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		number = number * str_base;
		number = number  + base(str[i], st_base);
		i++;
	}
	if (negative)
		return (-number);
	return (number);
}

// int	main(int ac, char **av)
// {
// 	int		number;
// 	if (ac >= 3)
// 	{
// 		number = ft_atoi_base(av[1], atoi(av[2]));
// 		printf("%d\n", number);
// 	}
// 	return (0);
// }