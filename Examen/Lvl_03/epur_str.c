/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:51:55 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/22 18:11:30 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void	epur_str(char *str)
{
	int		i;
	char	space;

	i = 0;
	space = -1;
	while(str[i])
	{
		if(str[i] != ' ' && str[i] != '\t')
		{
			if (space == 1)
				write(1, " ", 1);
			space = 0;
			write(1, &str[i], 1);
		}
		else if (space == 0)
			space = 1;
		i++;
	}	
}
*/

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				if (argv[1][i + 1] > 32 && argv[1][i + 1] != '\0')
					write(1, " ", 1);
			}	
			else if (argv[1][i] != ' ' || argv[1][i] != '\t')
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
*/
