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

int	*ft_range(int start, int end)
{
	int	*ptr;
	int	len;

	if (start > end)
		len = start - end;
	else
		len = end - start;
	ptr = malloc(sizeof(int) * len + 1);
	if (!ptr)
		return (NULL);
	while (len >= 0)
	{
		ptr[len] = end;
		if (start > end)
			end++;
		else
			end--;
		len--;
	}
	return (ptr);
}

int	main(void)
{
	int	i;
	int	*ptr;

	i = 0;
	ptr = ft_range(-3, 3);
	while (ptr[i] != '\0')
		printf("%i\n", ptr[i++]);
	return (0);
}