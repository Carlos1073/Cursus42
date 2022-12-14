/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libs/getnextline/get_next_line.h"

// Función para liberar el mapa
//
static void	free_map(char **map, int height)
{
	while (--height >= 0)
		free(map[height]);
	free(map);
}

// Función para calcular la anchura del mapa
//
static int	get_width_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

// Función shit para la matriz
//
static int	parse_map(t_game *game, char **tmp, char *line)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game->heightmap - 1)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			tmp[i][j] = game->map[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	j = 0;
	while (j < ft_strlen(line))
	{
		tmp[i][j] = line[j];
		j++;
	}
	tmp[i][j] = '\0';
	return (**tmp);
}

// Esta función añade cada linea del mapa hasta completarlo,
// con cada linea se incrementa el valor del heightmap, lo cual
// nos permitirá generar el malloc
//
static int	add_line(t_game *game, char *line)
{
	int		i;
	char	**tmp;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	tmp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!tmp)
		return (0);
	tmp[game->heightmap] = NULL;
	while (i < game->heightmap)
	{
		tmp[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!tmp)
			return (0);
		i++;
	}
	parse_map(game, tmp, line);
	free_map(game->map, game->heightmap - 1);
	game->map = tmp;
	i = -1;
	while (++i < game->heightmap)
		game->map[i] = tmp[i];
	return (1);
}

// Función para leer el mapa y verificar que se puede abrir
//
int	reading_map(t_game *game, char **argv)
{
	char	*line;
	int		i;

	line = "";
	game->widthmap = 0;
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		ft_errors(game, ERROR_4);
	i = 0;
	while (line != NULL)
	{
		line = get_next_line(game->fd);
		if (line && !game->widthmap)
			game->widthmap = get_width_map(line);
		if (line && game->widthmap != get_width_map(line))
			ft_errors(game, ERROR_5);
		if (!add_line(game, line))
			break ;
		free (line);
	}
	close(game->fd);
	if (!game->map)
		ft_errors(game, ERROR_7);
	game->widthmap = get_width_map(game->map[0]);
	return (1);
}
