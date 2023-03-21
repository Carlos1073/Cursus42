/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:10:45 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/16 17:07:51 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    exit_table(t_table *table, t_philo *philos)
{
    int i;

    i = -1;
    while (++i < table->n_philos)
        pthread_join(philos[i].thread_id, NULL);
    i = -1;
    while (++i < table->n_philos)
        pthread_mutex_destroy(&(table->forks[i]));
    pthread_mutex_destroy(&(table->printing));
}
