/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:05:41 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/28 17:55:43 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putstr(char const *str)
{
	int i;
	
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char const *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 3)
	{	
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i += 1;
		if (!argv[1][i])
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

// int ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	i;
// 	int	j;
// 	int	count;

// 	i = 0;
// 	j = 0;
// 	count = 0;
// 	if (argc == 3)
// 	{
// 		while(argv[1][i])
// 		{
// 	  		while(argv[2][j])
// 			{
// 				if(argv[1][i] == argv[2][j])
// 				{
// 					j++;
// 					count++;
// 					break;
// 				}
// 				else
// 					j++;
// 			}
// 		i++;
// 		}
// 		if(count == ft_strlen(argv[1]))
// 			putstr(argv[1]);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

