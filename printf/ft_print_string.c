/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:29:16 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/01 15:51:39 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_string(char *s)
{	
	int	i;

	i = 0;

	if (s == NULL)
	{
		ft_print_string("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
	i++;
	}
	return (i);
}
