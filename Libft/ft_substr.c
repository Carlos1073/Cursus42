/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:36:54 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/12 14:47:11 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	slen;
	char	*new;

	slen = ft_strlen((char *)(s));
	i = 0;
	if (!s)
		return (NULL);
	if (slen < start)
		return (0);
	new = malloc(sizeof(char) * (len - start + 1));
	if (!new)
		return (NULL);
	while (new[i])
	new[i] = '\0';
	return (new);
}
