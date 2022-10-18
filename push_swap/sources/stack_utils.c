/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:41:54 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:41:57 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creamos el stack con los valores recibidos y devolvemos el nuevo stack
//
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = -1;
	new->t_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

// Colocar un valor al final del stack
//
void	stack_bottom1(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

// Devuelve el último valor del stack
//
t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && (stack->next != NULL))
		stack = stack->next;
	return (stack);
}

// Devuelve del segundo al último valor del stack
//
t_stack	*get_stack_to_bottom(t_stack *stack)
{
	while (stack && stack->next && (stack->next->next != NULL))
		stack = stack->next;
	return (stack);
}

// Calculamos cuántos elementos hay en el stack A
//
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
