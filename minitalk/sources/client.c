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

static void	ft_errors(int i)
{
	if (i == ERROR_0)
		ft_printf("Error!\n");
	else if (i == ERROR_1)
		ft_printf("Invalid parameters!");
	exit(EXIT_FAILURE);
}

static void	decode(unsigned char c, pid_t pid)
{
	int				i;
	unsigned int	base;

	i = 7;
	base = 128;
	while (i >= 0)
	{
		if (c < base)
		{
			ft_simpletxt('0');
			if (kill(pid, SIGUSR1) == -1)
				ft_errors(ERROR_0);
		}
		else
		{
			ft_simpletxt('1');
			if (kill(pid, SIGUSR2) == -1)
				ft_errors(ERROR_0);
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
			ft_simpletxt('\n');
			count++;
		}
		decode('\n', srv_pid);
	}
	else
		ft_errors(ERROR_1);
	return (0);
}
