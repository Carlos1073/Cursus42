/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:11:27 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/20 14:11:30 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	int		i;
	size_t	len;
	char	*new;
	
	i = 0;
	len = ft_strlen(src);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (src[i])
	{	
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	main(void)
{
	char	*src;
	char	*new;

	src = (char*)malloc(sizeof(char) * 5);
	src = "Hola";
	printf("Source is: %s\n", src);
	new = ft_strdup(src);
	printf("New is: %s\n", new);
	return (0); 
}