/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:03:40 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/27 12:21:26 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_abs_val(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	*ft_range(int start, int end)
{
	int	size;
	int	*ptr;
	int	*tmp;

	size = end - start;
	if (!size)
		return (NULL);
	ptr = (int *) malloc(sizeof(int) * size);
	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (start <= end)
		*ptr++ = start++;
	return (tmp);
}

int	main(void)
{
	int	start;
	int	end;
	int	*array;
	int	i;

	start = -2;
	end = 3;
	i = 0;
	array = ft_range(start, end);
	while (i < 1 + ft_abs_val(end - start))
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("\n");
}
