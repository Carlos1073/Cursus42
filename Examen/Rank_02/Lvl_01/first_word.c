/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:42:48 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/19 09:51:45 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i++;
		while (argv[1][i] != 32 && argv[1][i] != 9 && argv[1][i])
		{
			write (1, &argv[1][i], 1);
			i++;
		}
	}	
	write (1, "\n", 1);	
}
