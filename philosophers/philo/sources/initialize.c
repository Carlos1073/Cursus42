/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:31:39 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/16 16:47:15 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	init_table(t_table *table, char **argv)
{
	table->dead_philos = 0;
	table->n_philos = ft_atoi(argv[1]);
	printf("N_philos: %i\n", table->n_philos);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		table->n_meals = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) == 0)
		{
			ft_errors(ERROR_3);
			return (EXIT_FAILURE);
		}
	}
	else
	 	table->n_meals = -1;
	printf("N_MEALS: %d\n", table->n_meals);
	return (EXIT_SUCCESS);
}

int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!table->forks)
		return (EXIT_FAILURE);
	while (i < table->n_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->printing, NULL);
	return (EXIT_SUCCESS);
}

int	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	table->philosophers = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philosophers)
		return (EXIT_FAILURE);
	while (i < table->n_philos)
	{
		table->philosophers[i].id = i + 1;
		table->philosophers[i].x_eaten = 0;
		table->philosophers[i].left_fork = i;
		table->philosophers[i].right_fork = i - 1;
		table->philosophers[i].t_last_meal = 0;
		table->philosophers[i].table = table;
		i++;
	}
	table->philosophers[0].right_fork = i - 1;
	return (EXIT_SUCCESS);
}

long long int	get_time(void)
{
	static struct	timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}