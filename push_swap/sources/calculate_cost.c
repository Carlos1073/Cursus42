/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:39:05 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:39:07 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funciones para el cálculo de movimientos
//
// Esta función calcula el coste de mover elementos del stack B a su posición
// correcta en el stack A. Se calculan dos costes: el cost_b nos dice el coste
// de llevar el elemento a la parte superior del stack B, mientras que el cost_a
// nos muestra el coste de llevar el elemento a su posición correcta en el
// stack A. Si dicho elemento se encuentra en la mitad inferior del stack, el
// coste será negativo; si se encuentra en la mitad superior del stack, el
// coste será positivo.
//
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = get_stack_size(temp_a);
	size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->position;
		if (temp_b->position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->position) * -1;
		temp_b->cost_a = temp_b->t_position;
		if (temp_b->t_position > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->t_position) * -1;
		temp_b = temp_b->next;
	}
}

// Esta función calcula cuál es el número del stack B con el coste más bajo
// de moverse al stak A, tras lo cual lo mueve a s posición final correcta.
//
void	get_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (get_absolute_value(temp->cost_a)
			+ get_absolute_value(temp->cost_b) < get_absolute_value(cheapest))
		{
			cheapest = get_absolute_value(temp->cost_b)
				+ get_absolute_value(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
