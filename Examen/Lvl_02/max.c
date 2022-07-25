/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:05:09 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/21 12:31:57 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		max(int* tab, unsigned int len)
{
	int	i;
	int	n_max;
	
	i = 0;
	n_max = tab[0];
	if (!len)
		return (NULL);
	while (tab[i] <= len)
	{
		if (tab[i] > n_max)
			n_max = tab[i];
		i++;
	}
	return (n_max);
}
