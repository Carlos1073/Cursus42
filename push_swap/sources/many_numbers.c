/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:40:08 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:40:10 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Método para más de tres números, basado en ordenar tres números cada vez
// hasta lograr ordenarlos todos
//
// Esta función envía todos los números del stack A al stack B, excepto tres
//
static void	send_numbers_but3(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	stack_size;
	int	pushing;

	stack_size = get_stack_size(*stack_a);
	pushing = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushing < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushing++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushing > 3)
	{
		do_pb(stack_a, stack_b);
		pushing++;
	}
}

// Esta función, una vez ordenado el stack, cambia el stack A hasta que
// el valor más bajo está en la posición top. Si está en la mitad
// inferior del stack, lo rota al revés hasta su posición, de lo contrario
// lo rota hasta colocarlo en la posición top del stack. 
// 
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_position;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_position = get_lowest_index_position(stack_a);
	if (lowest_position > stack_size / 2)
	{
		while (lowest_position < stack_size)
		{
			do_rra(stack_a);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			do_ra(stack_a);
			lowest_position--;
		}
	}
}

// Esta función ordena una lista de más de tres números. Para ello envía
// primero todos los elementos al stack B y deja 3 en el stack A.
// A continuación, ordena esos tres números y se repite el proceso hasta
// que en el stack B no queden números que ordenar.
// 
void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	send_numbers_but3(stack_a, stack_b);
	simple_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		get_cheapest_move(stack_a, stack_b);
	}
	if (!stack_is_sorted(*stack_a))
		shift_stack(stack_a);
}
