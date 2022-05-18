/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:30:33 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/18 16:30:53 by caguerre         ###   ########.fr       */
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
/*

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while(s[i] != '\0')
	{	
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		if (i == 0 && s[i] != c)
			words++;
		i++;
	}
	//words++;
	return (words);
}

static char	ft_result(char const *s, char **array, char c)
{
	int		i;
	int		j;
	size_t	winit;
	size_t	wend;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			winit = i;
		if (i == 0 && s[0] != c)
			winit = 0;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			wend = i;
			array[j] = ft_substr(s, winit, (wend - winit + 1));
			j++;
		}
		i++;
	}
	return (**array);
}
char	**ft_split(char const *s, char c)
{
	int		j;
	int		r;
	char	**array;
	
	j = 0;
	r = ft_count_words(s, c);
	array = (char **)malloc(sizeof (char *) * (r + 1));
	if (!array)
		return (NULL);
	ft_result(s, array, c);
	array[j] = NULL;
	return (array);
}
*/
