/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:26:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/26 17:27:05 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_errors(int i)
{
	if (i == ERROR_0)
		ft_printf("Error!\n");
	else if (i == ERROR_2)
		ft_printf("PID is invalid!");
	else if (i == ERROR_3)
		ft_printf("Too many arguments!");
	exit(EXIT_FAILURE);
}

static void	decode(int sig, siginfo_t *info, void *context)
{
	static int	count = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR2)
		c = c | 128 >> count;
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_errors(ERROR_0);
	count++;
	if (count == 8)
	{
		if (c == '\0')
		{
			ft_simpletxt('\n');
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_errors(ERROR_0);
		}
		else
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_errors(ERROR_0);
		write(1, &c, 1);
		c = 0;
		count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig1;
	struct sigaction	sig2;
	pid_t				pid;

	(void)argv;
	if (argc != 1)
		ft_errors(ERROR_3);
	pid = getpid();
	if (!pid)
		ft_errors(ERROR_2);
	ft_printf("PID is: %d\n", (int)pid);
	sig1.sa_flags = SA_SIGINFO;
	sig1.sa_sigaction = decode;
	sigaction(SIGUSR1, &sig1, NULL);
	sig2.sa_flags = SA_SIGINFO;
	sig2.sa_sigaction = decode;
	sigaction(SIGUSR2, &sig2, NULL);
	while (1)
		sleep(100);
	return (0);
}
