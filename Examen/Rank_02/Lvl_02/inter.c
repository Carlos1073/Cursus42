#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k[256];

	i = 0;
	while (i < 256)
	{
		k[i] = 1;
		i++;
	}

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[2][j] == argv[1][i])
			{
				if (k[(int)argv[1][i]])
					write(1, &argv[2][j], 1);
				k[(int)argv[1][i]] = 0;
			}

			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
