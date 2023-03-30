/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:37 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/30 15:41:23 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>
#include "colors.h"

typedef long long t_ll;

enum 
{
ERROR_0,
ERROR_1,
ERROR_2,
ERROR_3,
ERROR_4,
ERROR_5,
ERROR_6,
ERROR_7,
};

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	int				x_eaten;
	int				need_eat;
	long long		t_last_meal;
	pthread_t		thread_id;
	int				right_fork;
	int				left_fork;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				n_philos;
	int				dead_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				n_meals;
	long long int	start_time;
	int				all_eaten;
	pthread_mutex_t	death;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	t_philo			*philosophers;
}	t_table;

// CHECK PARAMETERS

void	ft_errors(int i);
int		check_parameters(int argc, char **argv);

// INITIALIZE

int				init_table(t_table *table, char **argv);
int				init_mutex(t_table *table);
int				init_philosophers(t_table *table);
long long int	get_time(void);

// ROUTINE

int		launch_table(t_table *table);
void	*philos_routine(void *void_philo);
int		check_dead_philos(t_table *table, t_philo *philo);
void	philo_eats(t_philo *philo);
void	exit_table(t_table *table, t_philo *philos);

// UTILS

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		print_action(t_table *table, int id, char *text);
void		print_action_death(t_table *table, int id, char *text);
void		ft_usleep(int n);

#endif
