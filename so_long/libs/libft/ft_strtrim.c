/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:32:22 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/16 17:26:45 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		init;
	int		end;

	init = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[init] && ft_strchr(set, (int)s1[init]))
		init++;
	while (end >= 0 && ft_strchr(set, (int)s1[end]))
		end--;
	new = (ft_substr(s1, init, end - init + 1));
	return (new);
}
