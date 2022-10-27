/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:58 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/22 13:05:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k[256];

	i = 0;
	while (i < 256)
	{
		k[i] = 1;
		i++;
	}
	
	i = 0;
	j = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (k[argv[1][i]])
			write(1, &argv[1][i], 1);
		k[argv[1][i]] = 0;
	i++;
	}
	while (argv[2][j])
	{
		if (k[argv[2][j]])
			write(1, &argv[2][j], 1);
		k[argv[2][j]] = 0;
	j++;
	}
	write(1, "\n", 1);
	return (0);
}
