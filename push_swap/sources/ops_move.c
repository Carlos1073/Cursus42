/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:40:20 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:40:23 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Operaciones de MOVE
//
// Esta función rota ambos stacks (A y B) hasta que uno de ellos está en
// posición. El coste dado es positivo porque ambas posiciones están en la mitad
// superior de sus respectivos stacks. El coste es reducido a medida que stacks
// van siendo rotados, cuando uno alcanza 0, el stack ha sido rotado lo máximo
// posible y la posición top es correcta.
//
static void	do_rotate_both(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack_a, stack_b);
	}
}

// Esta función rota el stack A hasta que está en posición. Si el coste es
// negativo, el stack será rotado al revés, mientras que si es positivo
// será rotado.
//
static void	do_rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(stack_a);
			(*cost)++;
		}
	}
}

// Esta función rota el stack B hasta que está en posición. Si el coste
// es negativo, el stack será rotado al revés, mientras que si es
// positivo será rotado.
//
static void	do_rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(stack_b);
			(*cost)++;
		}
	}
}

// Esta función hace un rotate reverse a ambos stacks (A y B) hasta
// que uno de ellos esté en posición. El coste es negativo porque ambas
// posiciones están en la mitad inferior de sus respectivos stacks.
// El coste se incrementará a medida que los stacks son rotados, cuando
// uno alcance 0 el stack se habrá rotado todo lo posible y la posición
// superior será correcta 
//  
static void	do_rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stack_a, stack_b);
	}
}

// Esta función  elige qué movimiento hacer para pasar el número del
// stack B a su posición correcta en el stack A. Si el coste de mover
// los stacks A y B a la posición coincide, ambos serán rotados al
// mismo tiempo También pueden rotarse por separado antes de colocar
// el número que esté más arriba en el stack B a  lo más alto
// del stack A.
//
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}
