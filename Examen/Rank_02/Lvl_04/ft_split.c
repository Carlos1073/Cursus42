/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:34:11 by caguerre          #+#    #+#             */
/*   Updated: 2023/01/17 14:34:15 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isblank(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	words;

	words = 0;
	while (*str && ft_isblank(*str))
		str++;
	while (*str)
	{
		if (*str && !ft_isblank(*str))
			words++;
		while (*str && !ft_isblank(*str))
			str++;
		while (*str && ft_isblank(*str))
			str++;
	}
	return (words);
}

int	ft_wordlen(char *str)
{
	int	len;

	len = 0;
	while (*str && !ft_isblank(*str))
	{
		str++;
		len++;
	}
	return (len);
}

char **ft_split(char *str)
{
	int	n_words;
	int	word_index;
	int	letter_index;
	char **new;

	n_words = word_count(str);
	word_index = 0;
	new = (char **)malloc(sizeof(char *) * n_words + 1);
	if (!new)
		return (NULL);
	while (word_index < n_words)
	{
		while (*str && ft_isblank(*str))
			str++;
		if (*str && !ft_isblank(*str))
		{
			new[word_index] = (char *)malloc(sizeof(char) * ft_wordlen(str) + 1);
			if (!new[word_index])
				return (NULL);
		}
		letter_index = 0;
		while (*str && !ft_isblank(*str))
		{
			new[word_index][letter_index] = *str;
			letter_index++;
			str++;
		}
		new[word_index][letter_index] = '\0';
		word_index++;
	}
	new[word_index] = NULL;
	return (new);
}