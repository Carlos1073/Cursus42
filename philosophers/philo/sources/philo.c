/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:03 by caguerre          #+#    #+#             */
/*   Updated: 2023/02/23 12:04:11 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char **argv)
{
	t_table    *table;
	
	if(argc != 5 && argc != 6)
	{
		ft_errors(ERROR_0);
		return (EXIT_FAILURE);
	}
	if (check_parameters(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (0);
	init_table(table, argv);
	printf("Initialized table\n");
	init_mutex(table);
	printf("Initialized mutex\n");
	init_philosophers(table);
	printf("Initialized philosophers\n");
	launch_table(table);
	return (0);
}
