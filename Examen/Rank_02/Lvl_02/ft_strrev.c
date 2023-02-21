#include <unistd.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{	
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int	main(void)
{
	char str[] = "Hello World";
	ft_strrev(str);
	printf("%s\n", str);
	return (0);
}
