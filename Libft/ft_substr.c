/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:36:54 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/16 12:11:56 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*new;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > (slen - start))
		len = slen - start;
	if (start > slen)
		len = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (len == 0)
		new[0] = '\0';
	else
		ft_strlcpy(new, &((char *)s)[start], len + 1);
	return (new);
}
