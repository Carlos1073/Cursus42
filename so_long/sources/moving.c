/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Con esta función comprobamos qué tipo de casilla es la que va a ocupar el
// jugador una vez se haya movido (E, 0 o C)
//
int  correct_move(t_game *game, int x, int y)
{
    if (game->map[y][x] == 'E')
    {
        if (game->collectables != 0)
            return (0);
        ft_printf("You have won the game!\n");
            exit_game(game);
    }
    if (game->map[y][x] == '0')
    {
        game->map[y][x] = 'P';
        game->player_x = x;
        game->player_y = y;
        game->counter++;
    }
    if (game->map[y][x] == 'C')
    {
        game->map[y][x] = 'P';
        game->player_x = x;
        game->player_y = y;
        game->collectables--;
        game->counter++;
    }
    return (1);
}