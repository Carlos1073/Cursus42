/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:36:58 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/13 12:37:08 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_print_char(int c);
int	ft_print_string(char *s);
int	ft_print_ptr(unsigned long long nbr);
int	ft_print_hexa(unsigned long int nbr, char *base);
int	ft_print_dec(int nbr);
int	ft_print_unsigned(unsigned int nbr);

#endif
