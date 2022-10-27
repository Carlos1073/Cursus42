/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:05:09 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/21 13:15:39 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	i;
	int	n_max;
	
	i = 0;
	n_max = tab[0];
	if (!len)
		return (0);
	while (tab[i] <= len)
	{
		if (tab[i] > n_max)
			n_max = tab[i];
		i++;
	}
	return (n_max);
}

int	main(void)
{
	int				data[5] = {19, 10, 8, 17, 9};
	unsigned int	len;
	int				res;

	len = 5;
	res = max(data, len);
	printf("El max es: %d", res);
	return (0);
}
