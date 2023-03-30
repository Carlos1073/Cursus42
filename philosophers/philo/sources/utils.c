/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:53:36 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/30 16:16:17 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	res;

	i = 0;
	negative = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * negative);
}

void	print_action(t_table *table, int id, char *text)
{
	pthread_mutex_lock(&(table->printing));
	if (!(table->dead_philos))
	{
		printf(YELLOW "%lld ", get_time() - table->start_time);
		printf(RED "%d ", id);
		printf(GREEN "%s\n", text);
	}
	pthread_mutex_unlock(&(table->printing));
	return ;
}

void	print_action_death(t_table *table, int id, char *text)
{
	pthread_mutex_lock(&(table->printing));
	if (!(table->dead_philos))
	{
		printf(YELLOW "%lld ", get_time() - table->start_time);
		printf(RED "%d ", id);
		printf(GREEN "%s\n", text);
	}
	return ;
}

void	ft_usleep(int n)
{
	long long int	i;

	i = get_time();
	while (n > get_time() - i)
	{
		usleep(n / 2);
	}
}
