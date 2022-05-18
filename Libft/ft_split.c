#include <stdio.h>
#include "libft.h"

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

/*static int	ft_words(char const *s, unsigned int winit, size_t wlen)
{
	size_t	slen;
	char	*new;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (wlen > (slen - winit))
		wlen = slen - winit;
	if (winit > slen)
		wlen = 0;
	new = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!new)
		return (NULL);
	if (wlen == 0)
		new[0] = '\0';
	else
		ft_strlcpy(new, &((char *)s)[winit], wlen + 1);
	return (new);
}*/

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		r;
	size_t	winit;
	size_t	wend;
	char	**array;
	
	r = ft_count_words(s, c);
	array = (char **)malloc(sizeof (char *) * (r + 1));
	if (!array)
		return (NULL);
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
	array[j] = NULL;
	return (array);
}
