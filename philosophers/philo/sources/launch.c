/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:49:55 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/21 12:47:12 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_eats(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&(table->forks[philo->left_fork]));
	print_action(table, philo->id, "The philosopher has taken the left fork");
	pthread_mutex_lock(&(table->forks[philo->right_fork]));
	print_action(table, philo->id, "The philosopher has taken the right fork");
	pthread_mutex_lock(&(table->check_meal));
	print_action(table, philo->id, "The philosopher is eating");
	philo->t_last_meal = get_time() - philo->table->start_time;
	pthread_mutex_unlock(&(table->check_meal));
	manage_times(table->time_to_eat, table);
	(philo->x_eaten)++;
	pthread_mutex_unlock(&(table->forks[philo->left_fork]));
	pthread_mutex_unlock(&(table->forks[philo->right_fork]));
}

void	*philos_routine(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_table	*table;

	i = 0;
	philo = (t_philo *) void_philo;
	table = philo->table;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat/2);
	while (table->dead_philos == 0)
	{
		if (table->n_meals > 0)
		{
			if (philo->x_eaten < table->n_meals)
				philo_eats(philo);
			else if (philo->x_eaten == table->n_meals)
				return (0);
		}
		else
		philo_eats(philo);
		print_action(table, philo->id, "The philosopher is sleeping");
		manage_times(table->time_to_sleep, table);
		print_action(table, philo->id, "The philosopher is thinking");
		i++;
		if (table->all_eaten)
			break ;
	}
	return (0);
}

int	check_dead_philos(t_table *table, t_philo *philo)
{
	int	i;

		i = 0;
		while (i < table->n_philos)
		{
			pthread_mutex_lock(&(table->check_meal));
			if (table->time_to_die < (long long int)((get_time() - table->start_time) - philo[i].t_last_meal))
			{
				print_action(table, i, "The philosopher is dead");
				table->dead_philos = 1;
				return (1);
			}
			i++;
			pthread_mutex_unlock(&(table->check_meal));
			usleep (100);
		}
		i = 0;
		while (table->n_meals != -1 && i < table->n_philos)
		{
			i++;
			if (i >= table->n_philos && philo[i].x_eaten < table->n_meals)
				i = 0;
			if (philo[i].x_eaten >= table->n_meals)
			{
				table->all_eaten = 1;
				break ;
			}
		}
		return (0);
}

int	launch_table(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = table->philosophers;
	table->start_time = get_time();
	while (i < table->n_philos)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, philos_routine, &(philo[i])))
			return (1);
		philo[i].t_last_meal = get_time();
		i++;
	}
	while (42)
	{
		if (check_dead_philos(table, table->philosophers) || table->all_eaten)
			break ;
	}
	exit_table(table, philo);
	return (0);
}
