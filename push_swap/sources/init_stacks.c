/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:39:52 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:39:54 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rellenamos el stack A con los valores dados. Si los valores están fuera
// de rango, imprimimos "Error" y salimos.
//
t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;
	long int	number;

	stack_a = NULL;
	i = 1;
	number = 0;
	while (i < argc)
	{
		number = ft_atoi_long(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)number);
		else
			stack_bottom1(&stack_a, stack_new((int)number));
		i++;
	}
	return (stack_a);
}

// Indexamos los valores del stack en el orden final en que deberán quedar
// una vez los hayamos ordenado. Es importante indexarlos del primero al último
// Recibimos dos variables, el stack A y el numero de valores que contiene
//
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*top;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		top = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				top = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (top != NULL)
			top->index = stack_size;
	}
}
