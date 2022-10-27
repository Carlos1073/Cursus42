#include <unistd.h>
#include <stdio.h>
#include <libc.h>

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    return (c);
}

int get_digit(char c, int digits_base)
{
	int	max_digit;
	
	if (digits_base <= 10)
		max_digit = digits_base + '0';
	else
		max_digit = digits_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int	res;
    int	negative;
    int	digit;

	res = 0;
	negative = 1;
	if (*str == '-')
		negative = -1;
		++str;
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		res = res * str_base;
		res = res + (digit * negative);
		++str;
	}
	return (res);
}
