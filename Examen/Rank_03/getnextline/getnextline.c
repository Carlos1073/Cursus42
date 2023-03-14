/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:04 by caguerre          #+#    #+#             */
/*   Updated: 2023/03/14 15:09:05 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

char *get_next_line(int fd)
{
	int		i;
	int		reading;
    char	character;
	char	*line;

	i = 0;
	reading = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	line = (char *)malloc(sizeof(char) * 10000);
	if (!line)
		return (NULL);
	while ((reading = read(fd, &character, BUFFER_SIZE)) > 0)
	{
		line[i++] = character;
		if (character == '\n')
			break;
	}
	if ((line[i - 1] == '\0' && reading == 0) || reading == -1)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

// int main(void)
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("test", O_RDONLY);
// 	printf("main fd = %d\n", fd);
// 	line = get_next_line(fd);
// 	free(line);
// 	printf("main line = %s", line);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	return (0);
// }