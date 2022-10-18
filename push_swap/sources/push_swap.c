/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:41:42 by caguerre          #+#    #+#             */
/*   Updated: 2022/10/14 12:41:44 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función es la encargada de seleccionar un método de sorting u otro en
// función de si se trata de una lista de dos, tres o más de tres núneros. Para
// ello, recibirá tres variables: el stack A con los valores, el stack B vacío
// y la cantidad de números a ordenar
//
static void	push_swap_select(t_stack **stack_a, t_stack **stack_b,
int stack_size)
{
	if (stack_size == 2 && !stack_is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		simple_sort(stack_a);
	else if (stack_size > 3 && !stack_is_sorted(*stack_a))
		complex_sort(stack_a, stack_b);
}

// Esta pequeña función comprueba si en el stack A los números ya están
// ordenados, en cuyo caso haremos return 1 y no deberemos hacer nada.
//
int	stack_is_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

// Función principal. Declaramos stacks y tamaño del stack A. Después
// rellenamos el stack A con los valores dados, designamos el tamaño del
// mismo y asignamos un índice a cada valor para saber el orden en el
// que deberán quedar. Tras ejecutar push_swap, liberamos stacks.
//
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		ft_errors(ERROR_3);
	if (!arg_is_correct(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap_select(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
