/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:38:51 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:38:54 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Método para tres números
//
// Esta función encuentra cuál de los tres números tiene el índice más alto
//
static int	find_top_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}	
	return (index);
}

// Esta función ordena los tres números en función de su índice, al ser tres
// números hay seis posibles combinaciones y hemos de contemplarlas todas.
//
void	simple_sort(t_stack **stack)
{
	int	top;

	top = find_top_index(*stack);
	if ((*stack)->index == top)
		do_ra(stack);
	else if ((*stack)->next->index == top)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
