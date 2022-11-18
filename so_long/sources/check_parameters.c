/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:28 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:30 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Con esta función comprobamos que el muro horizontal superior y el inferior
// contengan todo '1' y por lo tanto sea correcto
//
static int  horizontal_walls(t_game *game)
{
    int i;

    i = 0;
    while (game->map[0][i] == '1')
        i++;
    if (i < game->widthmap)
        return (0);
    i = 0;
    while (game->map[game->heightmap - 1][i] == '1')
        i++;
    if (i < game->widthmap)
        return (0);
    return (1);
}

// Con esta función comprobamos que el muro vertical derecho y el izquierdo
// contengan todo '1' y por lo tanto sea correcto
//
static int  vertical_walls(t_game *game)
{
    int height;
    int width;

    height = 0;
    width = game->widthmap;
    while (height < game->heightmap)
    {
        if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
            return (0);
        height++;
    }
    return (1);
}

// Con esta función comprobamos que el mapa contenga los items que el juego
// necesita para poder funcionar (P, C y E), además de no tener ningún
// caracter que no sea P,C,E,1 y 0. Y que por lo tanto todo sea correcto
//
void    count_check(t_game *game, int height, int width)
{
    if (game->map[height][width] != '1' && game->map[height][width] != '0' &&
            game->map[height][width] != 'P' && game->map[height][width] != 'E' &&
            game->map[height][width] != 'C' && game->map[height][width] != '\n')
        ft_errors(game, ERROR_3);
    if (game->map[height][width] == 'C')
        game->columncount++;
    if (game->map[height][width] == 'P')
        game->playercount++;
    if (game->map[height][width] == 'E')
        game->exitcount++;
}

// Esta función se moverá línea a línea dentro del mapa e irá llamando a la
// función que comprueba que los items del juego estén presentes y también
// que sólo haya un jugador (P) y una salida (E)
//
void    check_items(t_game *game)
{
    int width;
    int height;

    height = 0;
    while (height < game->heightmap - 1)
    {
        width = 0;
        while (width <= game->widthmap)
        {
            count_check(game, height, width);
            width++;
        }
        height++;
    }
    if (!(game->playercount == 1 && game->columncount > 1 && game->exitcount == 1))
        ft_errors(game, ERROR_2);
}

// Con esta función chequeamos que tanto los muros horizontales como verticales
// del mapa estén cerrados, en caso contrario finaliza el programa.

void    check_walls(t_game *game)
{
    int v_walls;
    int h_walls;

    v_walls = vertical_walls(game);
    h_walls = horizontal_walls(game);
    if (!v_walls || !h_walls)
        ft_errors(game, ERROR_1);
}
