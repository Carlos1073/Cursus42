/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:41:29 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:41:31 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función asigna una posición a cada número dentro del stack, de arriba
// a abajo y en orden ascendente
//
static void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

// Esta función elige la mejor posición final de cada número dentro del stack A,
// en función del índice de un número del stack B que le pasamos. Primero
// comprueba si el índice de ese número puede ser ubicado en el stack A,
// mirando si en el stack A existe ya algún número con un índice mayor. En caso
// de no haberlo, busca en el stack A el número con el índice más bajo y asigna
// éste como el t_position.
//
static int	get_target(t_stack **na, int nb_index,
int target_ind, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *na;
	while (temp_a)
	{
		if (temp_a->index > nb_index && temp_a->index < target_ind)
		{
			target_ind = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_ind != INT_MAX)
		return (target_pos);
	temp_a = *na;
	while (temp_a)
	{
		if (temp_a->index < target_ind)
		{
			target_ind = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

// Esta función elige la posición en el stack A a cada número del stack A.
// La variable t_position es la posición que el número deberá ocupar en
// el stack B para ser ordenado correctamente. Esta posición sirve para
// calcular los costes de mover cada número a su posición correcta
// en el stack A.
//
void	get_target_position(t_stack **na, t_stack **nb)
{
	t_stack	*temp_b;
	int		t_position;

	temp_b = *nb;
	get_position(na);
	get_position(nb);
	t_position = 0;
	while (temp_b)
	{
		t_position = get_target(na, temp_b->index, INT_MAX, t_position);
		temp_b->t_position = t_position;
		temp_b = temp_b->next;
	}
}

// Esta función devuelve la posición actual del elemento con el índice más
// bajo dentro del stack  
//
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_position;
	int		lowest_index;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_position);
}
