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
	size_t	len_storage;

	i = 0;
	while (storage[i] && (storage[i] != '\n'))
		i++;
	if (!storage)
	{
		free (storage);
		return (NULL);
	}
	len_storage = ft_strlen(storage);
	str = (char *)malloc(sizeof (char) * (len_storage - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (storage[i])
		str[c++] = storage[i++];
	str[c] = '\0';
	return (str);
}

// Funcion principal
//
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	storage = ft_read_save(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_get_line(storage);
	storage = ft_save(storage);
	return (line);
}

// Main
//
//int main(void)
//{
//    int     fd;
//    char    *line;	
//
//    fd = open("test", O_RDONLY);
//	printf("main fd = %d\n", fd);
//	line = get_next_line(fd);
//	printf("main line = %s", line);
//*	while (line)
//    {
//        free(line); 
//		line = get_next_line(fd);
//        printf("%s", line);
//		}
//    return (0);
//}
