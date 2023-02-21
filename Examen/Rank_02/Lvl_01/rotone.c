/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:45:24 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/20 15:29:19 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 'Z' || argv[1][i] == 'z')
				argv[1][i] -= 25;
			else if (argv[1][i] >= 'A' && argv[1][i] < 'Z')
				argv[1][i] += 1;
			else if (argv[1][i] >= 'a' && argv[1][i] < 'z')
				argv[1][i] += 1;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
