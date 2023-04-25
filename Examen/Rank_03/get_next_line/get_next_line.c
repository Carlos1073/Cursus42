#include "get_next_line.h"

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
	while ((reading = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		line[i++] = character;
		if (character == '\n')
			break;
	}
	if ((!line[i - 1] && !reading) || reading == -1)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}
