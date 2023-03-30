/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:36:55 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/30 15:40:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_parameters(int argc, char **argv)
{
	int i;
	int count;

	if (argv[1][0] == '0')
	{
		ft_errors(ERROR_1);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		count = 0;
		while (argv[i][count] != '\0')
		{
			if (ft_isdigit((int)argv[i][count]))
				count++;
			else
			{
				ft_errors(ERROR_2);
				return (EXIT_FAILURE);
			}
		}
		i += 1;
	}
	return (EXIT_SUCCESS);
}
