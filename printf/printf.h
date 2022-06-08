/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:44:33 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/07 15:57:38 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

int		ft_printf(char const *str, ...);
int		ft_print_char(int c);
int		ft_print_string(char *s);
int		ft_print_ptr(void *);
int		ft_print_hexa(unsigned long nbr);
int		ft_print_hexaupper(unsigned long nbr);
int		ft_print_dec(unsigned long nbr);
int		ft_print_unsigned(unsigned int nbr);

#endif
