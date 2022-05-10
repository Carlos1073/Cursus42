/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:47:16 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/10 12:47:54 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	int				src_s;
	unsigned int	dest_s;
	unsigned int	i;

	src_s = 0;
	dest_s = 0;
	i = 0;
	while (src[src_s])
		src_s++;
	if (size == 0)
		return (src_s);
	while (dest[dest_s])
		dest_s++;
	if (size <= dest_s)
		return (size + src_s);
	while (size && (--size - dest_s) && src[i])
	{
		dest[dest_s + i] = src[i];
		i++;
	}
	dest[dest_s + i] = '\0';
	return (src_s + dest_s);
}
