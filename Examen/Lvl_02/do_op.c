/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:03:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/20 17:08:50 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libc.h>

int	main(int argc, char **argv)
{
	int		first;
	int		second;
	char	operator;
	int		res;

	first = atoi(argv[1]);
	second = atoi(argv[3]);
	operator = argv[2][0];
	if (argc == 4)
	{
		if (operator == '+')
			res = first + second;
		else if (operator == '-')
			res = first - second;
		else if (operator == '*')
			res = first * second;
		else if (operator == '/')
			res = first / second;
		else if (operator == '%')
			res = first % second;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}
