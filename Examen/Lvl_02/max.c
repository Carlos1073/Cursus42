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

int max(int *tab, unsigned int len)
{
	int result;
	int i;
	
	result = tab[i];
	i = 0;	
	if (!len)
		return (0);
	while(i < len)
	{
		if (result <  tab[i])
		{
			result = tab[i];
		}
		i++;
	}
	return result;
}

int	main(void)
{
	int				data[5] = {19, 20, 8, 30, 9};
	unsigned int	len;
	int				res;

	len = 5;
	res = max(data, len);
	printf("El max es: %d", res);
	return (0);
}
