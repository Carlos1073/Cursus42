/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:25:45 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/23 15:58:53 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*ft_new(char *new, int n, size_t len)
{
	len--;
	while (n > 0)
	{
		new[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (new);
}

static char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (start);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*new;

	len = ft_count(n);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (n == 0)
		new[0] = '0';
	if (n == -2147483648)
		return (ft_strcpy(new, "-2147483648"));
	if (n < 0)
	{		
		n = -n;
		new[0] = '-';
	}
	new = ft_new(new, n, len);
	new[len] = '\0';
	return (new);
}
