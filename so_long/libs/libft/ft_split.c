/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:30:33 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/27 09:53:28 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(int i, char **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (0);
}

static char	*ft_makewords(char const *s, unsigned int start, size_t len)
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

static size_t	ft_strlenchar(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		r;
	char	**array;
	size_t	i_tmp;

	r = ft_count_words(s, c);
	array = (char **)malloc(sizeof (char *) * (r + 1));
	if (!array)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i] != '\0')
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c) || (i == 0 && s[0] != c))
		{
			i_tmp = ft_strlenchar(&s[i], c);
			array[++j] = ft_makewords(&s[i], 0, i_tmp);
			if (array[j] == NULL)
				return (ft_free(j, array));
			i += i_tmp - 1;
		}
	}
	array[r] = NULL;
	return (array);
}
