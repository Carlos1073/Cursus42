/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:58 by caguerre          #+#    #+#             */
/*   Updated: 2023/01/26 15:13:12 by caguerre         ###   ########.fr       */
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
		if (k[(int)argv[1][i]])
			write(1, &argv[1][i], 1);
		k[(int)argv[1][i]] = 0;
	i++;
	}
	while (argv[2][j])
	{
		if (k[(int)argv[2][j]])
			write(1, &argv[2][j], 1);
		k[(int)argv[2][j]] = 0;
	j++;
	}
	write(1, "\n", 1);
	return (0);
}
