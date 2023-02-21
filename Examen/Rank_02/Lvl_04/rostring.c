#include <unistd.h>
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		if (i == 0 && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

int mount_string(char *str, int start, int end, int init)
{
	int	j;
	int flag;
	int	words;
	char	c;

	c = ' ';
	j = init;
	flag = 0;
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\t')
			flag = 1;
		if (!(str[j] == ' ' || str[j] == '\t'))
		{
			if (flag)
				write(1, " ", 1);
			flag = 0;
			write(1, &str[j], 1);
		}
		j++;
	}
	words = ft_count_words(str, c);
	if (words > 1)
		write(1, " ", 1);
	while (start <= end)
	{	
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;
	int		init;
	char	*str;

	str = argv[1];
	i = 0;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	start = i;
	while (argv[1][i] >= 33 && argv[1][i] <= 127)
	{
		if (argv[1][i] != ' ' || argv[1][i] != '\t')
			end = i;
		i++;
	}
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	init = i;
	mount_string(str, start, end, init);
	return (0);
}