/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:40:49 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:40:50 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Operaciones de ROTATE-1
//
// Esta función mueve todos los números hacia arriba una posición, de modo
// que el primero pasará a ser el último, el segundo se convertirá en
// el primero. etc.
//
static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = get_stack_bottom(*stack);
	temp->next = NULL;
	last->next = temp;
}

// Esta función llama a la función ra (para el stack A) y escribe en
// pantalla el movimiento efectuado
// 
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

// Esta función llama a la función rb (para el stack B) y escribe en
// pantalla el movimiento efectuado
//
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

// Esta función envía el elemento top de ambos stacks (A y B) a lo más
// bajo de sus respectivos stacks. Luego escribe en pantalla el
// movimiento efectuado.
// 
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
