/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:28 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:30 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Con esta función duplicamos el mapa para poder trabajar con él, ya que
// haremos cambios varios y eso conllevaría que luego no funcione nada
//
void	**copying_map(t_game *game)
{
	int		i;
	char	**copymap;

	copymap = (char **)malloc(sizeof(char *) * (game->widthmap + 1));
	if (!copymap)
		free (copymap);
	i = 0;
	while (game->map[i])
	{
		copymap[i] = ft_strdup(game->map[i]);
		i++;
	}
	copymap[i] = NULL;
	game->map_tmp = copymap;
	return (0);
}

// Con esta función localizamos las coordenadas del player para comenzar
// a revisar el mapa a partir de ahí
//
void	get_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while ((game->map[y][x] != '\0'))
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

// void	print_map(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (game->map_tmp != NULL)
// 	{
// 		while (game->map_tmp[i])
// 		{
// 			j = 0;
// 			while (game->map_tmp[i][j])
// 			{
// 				printf("%c", game->map_tmp[i][j]);
// 				j++;
// 			}
// 			i++;
// 		}
// 	}
// printf("\n");
// }

// Función boleana para revisar todas las casillas en busca de un camino
// que vaya del Player al Exit, para ello iremos restando los coleccionables
// y buscando la  salida, eso significará que si ambas condiciones son exitosas
// el path es válido

bool	check_path_to_exit(t_game *game, int y, int x)
{
	if (game->map_tmp[y][x] == 'V')
		return (false);
	if (game->map_tmp[y][x] == '1')
		return (false);
	if (game->map_tmp[y][x] == 'C' && game->columncount > 0)
		game->columncount--;
	if (game->map_tmp[y][x] == 'E')
		game->reachable_exit++;
	if (game->reachable_exit == game->exitcount && game->columncount <= 0)
		return (true);
	game->map_tmp[y][x] = 'V';
	check_path_to_exit(game, y, x + 1);
	check_path_to_exit(game, y, x - 1);
	check_path_to_exit(game, y + 1, x);
	check_path_to_exit(game, y - 1, x);
	if (game->reachable_exit == game->exitcount && game->columncount == 0)
		return (true);
	return (false);
}
