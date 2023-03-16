/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:49:55 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/16 11:29:48 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_eats(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&(table->fork_mutex[philo->left_fork]));
	print_action(table, philo->id, "The philosopher has taken left fork");
	pthread_mutex_lock(&(table->fork_mutex[philo->right_fork]));
	print_action(table, philo->id, "The philosopher has taken right fork");
	pthread_mutex_lock(&(table->check_meal));
	print_action(table, philo->id, "The philosopher is eating");
	philo->t_last_meal = get_time() - philo->table->start_time;
	pthread_mutex_unlock(&(table->check_meal));
	manage_times(table->time_to_eat, table);
	(philo->x_eating)++;
	pthread_mutex_unlock(&(table->fork_mutex[philo->left_fork]));
	pthread_mutex_unlock(&(table->fork_mutex[philo->right_fork]));
}

void	*philos_routine(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_table	*table;

	i = 0;
	philo = (t_philo *) void_philo;
	table = philo->table;
	if (philo->id % 2)
		usleep(15000);
	while (table->dead_philos == 0)
	{
		// if (table->n_meals > 0)
		// {
		// 	if (philo->x_eating < table->n_meals)
		// 		philo_eats(philo);
		// }
		// else
		// 	philo_eats(philo);
		if (table->n_meals == 0)
			break ;
		print_action(table, philo->id, "The philosopher is sleeping");
		manage_times(table->time_to_sleep, table);
		print_action(table, philo->id, "The philosopher is thinking");
		i++;
	}
	return (0);
}

void	check_dead_philos(t_table *table, t_philo *philo)
{
	int	i;

		i = 0;
		while (i < table->n_philos)
		{
			//pthread_mutex_lock(&(table->check_meal));
			if (table->time_to_die < (long long int)((get_time() - table->start_time) - philo[i].t_last_meal))
			{
				print_action(table, i, "The philosopher is dead");
				table->dead_philos = 1;
				exit(1);
			}
			i++;
			//pthread_mutex_unlock(&(table->check_meal));
		//	usleep (100);
		}
	//	if (table->dead_philos != 0)
	//		break ;
		i = 0;
		while (table->n_meals != -1 && i < table->n_philos && philo[i].x_eating >= table->n_meals)
			i++;
		if (i == table->n_philos)
			table->all_eat = 1;
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
		check_dead_philos(table, table->philosophers);
	exit_table(table, philo);
	return (0);
}
