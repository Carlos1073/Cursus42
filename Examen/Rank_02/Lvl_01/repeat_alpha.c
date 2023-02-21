/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:14:06 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/19 12:48:11 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_count(char c)
{
	int	repeat;

	repeat = 1;
	if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	return (repeat);
}

int	main(int argc, char **argv)
{
	int	i;
	int	repeat;
	
	i = 0;
	if (argc == 2)
		while (argv[1][i])
		{
			repeat = ft_count(argv[1][i]);
			while (repeat--)
				write(1, &argv[1][i], 1);
			argv[1]++;
		}
	ft_putchar('\n');
}
