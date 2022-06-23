/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:45 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/23 12:43:36 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_dec(int nbr)
{
	int		i;
	char	*num;

	i = 0;
	num = ft_itoa(nbr);
	if (num == NULL)
		return (write(1, "(null)", 6));
	while (num[i])
	{
		if (write(1, &num[i], 1) == -1)
			return (-1);
		i++;
	}
	free(num);
	return (i);
}
