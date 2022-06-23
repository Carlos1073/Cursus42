/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:29:16 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/09 14:20:06 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_string(char *s)
{	
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if (write(1, &s[i], sizeof(char)) != sizeof(char))
			return (-1);
		i++;
	}
	return (i);
}
