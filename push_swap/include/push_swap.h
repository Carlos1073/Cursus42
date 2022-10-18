/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:36:58 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/13 12:37:08 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				value;
	int				position;
	int				t_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Errores en la entrada de argumentos

# define ERROR_0	(int)0
# define ERROR_1	(int)1
# define ERROR_2	(int)2
# define ERROR_3	(int)3

// Comprobación de valores

int			arg_is_correct(char **argv);
int			is_sign(char c);
int			is_digit(char c);
int			compare(const char *s1, const char *s2);

// Iniciando el proceso

t_stack		*fill_stack(int argc, char **argv);
void		stack_bottom1(t_stack **stack, t_stack *new);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_to_bottom(t_stack *stack);
int			get_stack_size(t_stack *stack);
void		assign_index(t_stack *stack_a, int stack_size);

// Manejo del stack

t_stack		*stack_new(int value);
int			stack_is_sorted(t_stack *stack_a);
void		get_target_position(t_stack **na, t_stack **nb);
int			get_lowest_index_position(t_stack **stack);
int			get_absolute_value(int num);

// Utilidades

void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
long int	ft_atoi_long(const char *str);

// Operaciones push y swap

void		do_sa(t_stack **stack_a);
//void		do_sb(t_stack **stack_b);
//void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_move(t_stack **stack_a, t_stack **stack_b,
				int cost_a, int cost_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

// Metodos de ordenamiento

void		simple_sort(t_stack **stack);
void		complex_sort(t_stack **stack_a, t_stack **stack_b);

// Cálculo de costes

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		get_cheapest_move(t_stack **stack_a, t_stack **stack_b);

// Gestión de errores

void		ft_errors(int i);

#endif
