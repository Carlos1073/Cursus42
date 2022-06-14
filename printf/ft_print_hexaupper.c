/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexaupper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:26:06 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/09 14:19:04 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_hexaupper(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_print_hexaupper(nbr / 16);
		len += ft_print_hexaupper(nbr % 16);
	}
	else
		len += write(1, &"0123456789ABCDEF"[nbr], 1);
	return (len);
}
