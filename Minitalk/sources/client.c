/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:14:38 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/26 19:15:07 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	decode(unsigned char c, pid_t pid)
{
	int				i;
	unsigned int	base;

	i = 7;
	base = 128;
	while (i >= 0)
	{
		if (c < base)
		{
			ft_putchar('0');
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_putchar('1');
			kill(pid, SIGUSR2);
			c = c - base;
		}
		base = base / 2;
		i--;
		usleep(200);
	}
}

int	main(int args, char **argv)
{
	int	count;
	int	srv_pid;

	count = 0;
	if (args == 3)
	{
		srv_pid = ft_atoi(argv[1]);
		while (argv[2][count])
		{
			decode(argv[2][count], srv_pid);
			ft_putchar('\n');
			count++;
		}
		decode('\n', srv_pid);
	}
	return (0);
}
