/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:49:55 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:19 by caguerre         ###   ########.fr       */
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
	philo = (t_philo *)void_philo;
	table = philo->table;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);
	while (table->dead_philos == 0)
	{
		if (table->n_meals > 0)
		{
			if (philo->x_eaten == table->n_meals)
			{
				// print_action_death(table,
						// i,"The philosopher has completed the routine");
				break ;
				// return ((0));
			}
			else
				philo_eats(philo);
		}
		else
			philo_eats(philo);
		if (philo->x_eaten != table->n_meals)
		{
			print_action(table, philo->id, "The philosopher is sleeping");
			manage_times(table->time_to_sleep, table);
			print_action(table, philo->id, "The philosopher is thinking");
		}
		i++;
	}
	return (0);
}

int	check_dead_philos(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (table->time_to_die < (long long int)((get_time()
					- table->start_time) - philo[i].t_last_meal))
		{
			print_action_death(table, i, "The philosopher is dead");
			table->dead_philos = 1;
			return (1);
		}
		i++;
	}
	i = 0;
	while (table->n_meals != -1 && i < table->n_philos)
	{
		i++;
		if (i >= table->n_philos && philo[i].x_eaten < table->n_meals)
			i = 0;
		if (philo[i].x_eaten == table->n_meals)
		{
			// print_action_death(table, i, "Routine completed");
			table->all_eaten = 1;
			return (1);
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
	// table->start_time = get_time() * (table->n_philos * 100);
	while (i < table->n_philos)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, philos_routine,
				&(philo[i])))
			return (1);
		philo[i].t_last_meal = get_time();
		i++;
	}
	while (42)
	{
		if (check_dead_philos(table, table->philosophers))
			break ;
	}
	exit_table(table, philo);
	return (0);
}
