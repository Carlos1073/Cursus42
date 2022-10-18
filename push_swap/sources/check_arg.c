/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:39:22 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:39:24 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprobamos los argumentos dados. 
//
// Primero comprobamos si el argumento es un número. Si es correcto, return 1.
//
static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

// Comprobamos si el argumento es cero y si ese cero tiene asignado un
// positivo o negativo. Si es correcto, return 1.
//
static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

// Comprobamos si hay algún valor duplicado en los argumentos utilizando una
// función secundaria. Si hay alguno, return 1.
//
static int	arg_is_duplicated(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && compare(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Esta es la función principal que chequea que los argumentos sean correctos
// para poder proceder. Si todo es correcto, return 1.
//
int	arg_is_correct(char **argv)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			ft_errors(ERROR_0);
		zero += arg_is_zero(argv[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (arg_is_duplicated(argv))
		ft_errors(ERROR_2);
	return (1);
}
