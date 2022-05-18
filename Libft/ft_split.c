/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:30:33 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/18 17:13:04 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		if (i == 0 && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		r;
	size_t	winit;
	char	**array;

	r = ft_count_words(s, c);
	array = (char **)malloc(sizeof (char *) * (r + 1));
	if (!array)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			winit = i;
		if (i == 0 && s[0] != c)
			winit = 0;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			array[++j] = ft_substr(s, winit, (i - winit + 1));
	}
	array[r] = NULL;
	return (array);
}
