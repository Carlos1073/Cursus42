/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:40:31 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:40:32 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Operaciones de PUSH
//
// Esta función envía todos los numeros del stack A al stack B
//
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

// Esta función llama a la función push y escribe en pantalla el movimiento
// efectuado
// 
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

// Esta función empuja el elemento top del stack B y lo coloca en el top del
// stack A. Luego escribe en pantalla el movimiento efectuado.
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
