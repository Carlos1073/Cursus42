/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:39:38 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:39:40 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprobar si el valor es un signo positivo o negativo
//
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

// Comprobar si el valor es un número o no
//
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

// Comprobamos si hay números repetidos en los argumentos. Si encuentra
// duplicaciones. return 0.
//
int	compare(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

// Mensajes de error en función de los argumentos recibidos
//
void	ft_errors(int i)
{
	if (i == ERROR_0)
		write(2, "Error\n", 6);
	else if (i == ERROR_1)
		write(2, "Error\n", 6);
	else if (i == ERROR_2)
		write(2, "Error\n", 6);
	else if (i == ERROR_3)
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
