/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:07:44 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/03 12:03:52 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_print_char(int c);
int		ft_print_string(char *s);
int		ft_print_hexa(unsigned long nbr);
int		ft_print_hexaupper(unsigned long nbr);
void	ft_putstr_fd(char *s, int fd);
int		ft_print_ptr(void *);

#endif
