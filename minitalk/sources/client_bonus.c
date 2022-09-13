/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
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

static int	ft_putstr_constant(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = write(1, "(NULL)", 6);
		return (i);
	}
	while (str[i])
		i = ft_simpletxt(str[i]);
	return (i);
}

static void	received(int sig)
{
	if (sig == 31)
	{
		usleep(100);
		ft_printf("Señal recibida %d \n", (int)sig);
	}
	else
	{
		ft_putstr_constant("Mensaje completo recibido\n");
		exit(1);
	}
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
			if (kill(pid, SIGUSR1) == -1)
				ft_errors(ERROR_0);
			usleep(500);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_errors(ERROR_0);
			usleep(500);
			c = c - base;
		}
		base = base / 2;
		i--;
		usleep(100);
	}
}

int	main(int args, char **argv)
{
	int	count;
	int	srv_pid;

	count = 0;
	if (args == 3)
	{
		signal(SIGUSR1, received);
		signal(SIGUSR2, received);
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
