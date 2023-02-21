/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:49:24 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/27 14:56:52 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	(void)argv;
// 	if (argc == 0)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}
// 	if (argc >= 1)
// 		ft_putnbr(argc - 1);
// 	write(1, "\n", 1);
// 	return (0);
// }

