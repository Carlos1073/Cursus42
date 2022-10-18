/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:41:18 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:41:20 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Operaciones de SWAP 
//
// Esta función hace swap con los dos primeros números del stack. Obviamente
// también lo hará si en el stack solo hay dos números. 
//
static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

// Esta función llama a la función swap y escribe en pantalla el movimiento
// efectuado
// 
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

// // Esta función llama a la función swap y escribe en pantalla el
// movimiento efectuado
// // 
// void	do_sb(t_stack **stack_b)
// {
// 	swap(*stack_b);
// 	write(1, "sb\n", 3);
// }

// // Esta función intercambia los dos elementos superiores del stack A y B
// y escribe el movimiento efectuado
// //
// void	do_ss(t_stack **stack_a, t_stack **stack_b)
// {
// 	swap(*stack_a);
// 	swap(*stack_b);
// 	write(1, "ss\n", 3);
// }
