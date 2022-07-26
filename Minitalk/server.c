/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:26:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/26 17:27:05 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    decoder(int sig, siginfo_t *info, void *context)
{
	static int	count;
	static char	c;

    count = 0;
    c = 0;
	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		c = c | 128 >> count;
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		c = 0;
		count = 0;
	}
}

int main(void)
{
	struct sigaction	sig1;
	struct sigaction	sig2;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID is %d", (int)pid);
	ft_print_char('\n');
	sig1.sa_flags = SA_SIGINFO;
	sig1.sa_sigaction = decoder;
	sigaction(SIGUSR1, &sig1, NULL);
	sig2.sa_flags = SA_SIGINFO;
	sig2.sa_sigaction = decoder;
	sigaction(SIGUSR2, &sig2, NULL);
	while (1)
		sleep(5);
	return (0);
}
