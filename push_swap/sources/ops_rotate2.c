/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:41:00 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:41:01 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Operaciones de ROTATE-2
//
// Esta función desplaza una posición hacia abajo todos los números, de modo
// que el último número pasa a ser el primero de la lista
//
static void	rotate_rev(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL)
		return ;
	first = get_stack_bottom(*stack);
	last = get_stack_to_bottom(*stack);
	temp = *stack;
	*stack = first;
	(*stack)->next = temp;
	last->next = NULL;
}

// Esta función llama a la función rra (reverse rotate para el stack A) y
// escribe en pantalla el movimiento efectuado
// 
void	do_rra(t_stack **stack_a)
{
	rotate_rev(stack_a);
	write(1, "rra\n", 4);
}

// Esta función envía los últimos números de cada stack (A y B) a la
// posición más alta de sus respectivos stacks. Luego escribe en pantalla
// el movimiento efectuado 
//
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_rev(stack_a);
	rotate_rev(stack_b);
	write(1, "rrr\n", 4);
}

// Esta función llama a la función rrb (reverse rotate para el stack B) y
// escribe en pantalla el movimiento efectuado
// 
void	do_rrb(t_stack **stack_b)
{
	rotate_rev(stack_b);
	write(1, "rrb\n", 4);
}
