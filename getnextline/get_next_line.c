/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:04:07 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/01 18:47:01 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Reservamos memoria para el buffer, Usamos READ para leer el archivo
// y concatenamos strings. Devolvemos STORAGE con las cadenas unidas.
//
char	*ft_read_save(int fd, char *storage)
{
	char	*buff;
	int		reading;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	reading = 1;
	while (!ft_strchr(storage, '\n') && reading != 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == -1)
		{
			free(buff);
			free(storage);
			return (NULL);
		}
		buff[reading] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

// Reservamos memoria para una nueva string y extraemos el contenido
// del STORAGE hasta que haya un salto de línea. Finalmente devolvemos
// la nueva string
//
char	*ft_get_line(char *storage)
{
	int		i;
	char	*str;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		str[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		str[i] = storage[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// Contamos los bytes hasta encontrar un salto de linea y reservamos
// memoria para el nuevo STORAGE, descontando esos bytes para
// quedarnos con el resto. Finalmente liberamos STORAGE y devolvemos
// la nueva string
//
char	*ft_save(char *storage)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	if (!storage)
	{
		free (storage);
		return (NULL);
	}
	while (storage[i] && (storage[i] != '\n'))
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	i++;
	c = 0;
	while (storage[i])
		str[c++] = storage[i++];
	str[c] = '\0';
	free(storage);
	return (str);
}

// Funcion principal
//
char	*get_next_line(int fd)
{
	static char	*storage[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
	{
		storage[fd] = ft_strdup("");
		if (!storage[fd])
			return (NULL);
	}
	storage[fd] = ft_read_save(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ft_get_line(storage[fd]);
	storage[fd] = ft_save(storage[fd]);
	return (line);
}

//Main

// int main(void)
// {
//    int     fd;
//    char    *line;

//    fd = open("test", O_RDONLY);
// 	printf("main fd = %d\n", fd);
// 	line = get_next_line(fd);
// //	free(line);
// 	printf("main line = %s", line);
// 	while (line)
// 	{
//     	free(line);
// 		line = get_next_line(fd);
//     	printf("%s", line);
// 	}
// 	return (0);
// }
