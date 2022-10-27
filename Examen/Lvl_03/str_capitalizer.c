/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:27:46 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/28 12:47:55 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	str_capitalizer(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] >= 'a' && 'z' >= str[i])
// 		str[i] -= 32;
// 	write(1, &str[i], 1);
// 	while (str[++i])
// 	{
// 		if (str[i] >= 'A' && 'Z' >= str[i])
// 			str[i] += 32;
// 		if (str[i] >= 'a' && 'z' >=  str[i] && (str[i - 1] == ' ' || str[i - 1] == '\t'))
// 			str[i] -= 32;
// 		write(1, &str[i], 1);
// 	}
// }
void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	return (0);
}
