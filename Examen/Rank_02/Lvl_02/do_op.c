/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:03:39 by caguerre          #+#    #+#             */
/*   Updated: 2023/01/26 17:16:14 by caguerre         ###   ########.fr       */
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

	if (argc == 4)
	{
		first = atoi(argv[1]);
		second = atoi(argv[3]);
		operator = argv[2][0];
		res = 0;
		if (operator == '+')
			res = first + second;
		if (operator == '-')
			res = first - second;
		if (operator == '*')
			res = first * second;
		if (operator == '/')
			res = first / second;
		if (operator == '%')
			res = first % second;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}
