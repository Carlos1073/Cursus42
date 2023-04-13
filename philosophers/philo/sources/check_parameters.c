/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:36:55 by caguerre          #+#    #+#             */
/*   Updated: 2023/04/13 10:35:48 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_parameters(int argc, char **argv)
{
	int	i;
	int	count;

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

int	only_one_philo(t_philo *philo, t_table *table)
{
	if (philo->table->n_philos == 1)
	{
		pthread_mutex_lock(&(table->forks[philo->left_fork]));
		print_action(table, philo->id,
			"The philosopher has taken the left fork");
		ft_usleep(philo->table->time_to_die + 1);
		philo->t_last_meal = get_time() - philo->table->start_time
			- philo->table->time_to_die;
		return (1);
	}
	return (0);
}
