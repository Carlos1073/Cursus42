/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:47:16 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/12 15:46:55 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	int				src_s;
	unsigned int	dst_s;
	unsigned int	i;

	src_s = 0;
	dst_s = 0;
	i = 0;
	while (src[src_s])
		src_s++;
	if (dstsize == 0)
		return (src_s);
	while (dst[dst_s])
		dst_s++;
	if (dstsize <= dst_s)
		return (dstsize + src_s);
	while (dstsize && (--dstsize - dst_s) && src[i])
	{
		dst[dst_s + i] = src[i];
		i++;
	}
	dst[dst_s + i] = '\0';
	return (src_s + dst_s);
}
