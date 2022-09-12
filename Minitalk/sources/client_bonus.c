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

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
		i = ft_putchar(str[i]);
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
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
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
			ft_putchar('\n');
			count++;
		}
		decode('\n', srv_pid);
	}
	return (0);
}
