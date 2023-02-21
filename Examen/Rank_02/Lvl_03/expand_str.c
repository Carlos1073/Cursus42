/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:24:47 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/22 17:26:56 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// void	expand_str(char *str)
// {
// 	int		i;
// 	char	space;

// 	i = 0;
// 	space = -1;
// 	while(str[i])
// 	{
// 		if(str[i] != ' ' && str[i] != '\t')
// 		{
// 			if (space == 1)
// 				write(1, "   ", 3);
// 			space = 0;
// 			write(1, &str[i], 1);
// 		}
// 		else if (space == 0)
// 			space = 1;
// 		i++;
// 	}	
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		expand_str(argv[1]);
// 	write(1, "\n", 1);
// 	return (0);
// }

// O tambe...

int	main(int argc, char *argv[])
{
	int	i;
	int flag;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flag)
					write(1, "   ", 3);
				flag = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

