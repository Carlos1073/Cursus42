/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:11:27 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/20 14:11:30 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i;

    if (!s1 || !s2)
        return (0);
    while (*s1)
    {
        i = 0;
        while (s2[i] != '\0')
        {
            if (*s1 == s2[i])
                return ((char *)s1);
            i++;
        }
        s1++;
    }
    return (0);
}

int main(void)
{
    const char  s[] = "xAAADff";
    const char  c[] = "D";

	printf("original: %s\n", strpbrk(s, c));
	printf("mio: %s\n", ft_strpbrk(s, c));
}
