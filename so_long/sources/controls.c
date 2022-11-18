/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Función para mover el jugador al pulsar la tecla W, si no hay un muro 
// ejecutará la función correct_move para ver qué tipo de casilla es
//
static int  move_up(t_game *game, int movement)
{
    int x;
    int y;
    int i;

    x = game->player_x;
    y = game->player_y;
    if (movement == 13)
    {   
        y--;
        if (game->map[y][x] == '1')
            return (0);
        i = correct_move(game, x, y);
        if (!i)
            return (0);
        game->map[y + 1][x] = '0';
    }
    ft_printf("Movements: %i\n", game->counter);
    ft_printf("Collectables left: %i\n", game->collectables);
    return (1);
}

// Función para mover el jugador al pulsar la tecla S, si no hay un muro 
// ejecutará la función correct_move para ver qué tipo de casilla es
//
static int  move_down(t_game *game, int movement)
{
    int x;
    int y;
    int i;

    x = game->player_x;
    y = game->player_y;
    if (movement == 1)
    {   
        y++;
        if (game->map[y][x] == '1')
            return (0);
        i = correct_move(game, x, y);
        if (!i)
            return (0);
        game->map[y - 1][x] = '0';
    }
    ft_printf("Movements: %i\n", game->counter);
    ft_printf("Collectables left: %i\n", game->collectables);
    return (1);
}

// Función para mover el jugador al pulsar la tecla A, si no hay un muro 
// ejecutará la función correct_move para ver qué tipo de casilla es
//
static int  move_left(t_game *game, int movement)
{
    int x;
    int y;
    int i;

    x = game->player_x;
    y = game->player_y;
    if (movement == 0)
    {   
        x--;
        if (game->map[y][x] == '1')
            return (0);
        i = correct_move(game, x, y);
        if (!i)
            return (0);
        game->map[y][x + 1] = '0';
    }
    ft_printf("Movements: %i\n", game->counter);
    ft_printf("Collectables left: %i\n", game->collectables);
    return (1);
}

// Función para mover el jugador al pulsar la tecla D, si no hay un muro 
// ejecutará la función correct_move para ver qué tipo de casilla es
//
static int  move_right(t_game *game, int movement)
{
    int x;
    int y;
    int i;

    x = game->player_x;
    y = game->player_y;
    if (movement == 2)
    {   
        x++;
        if (game->map[y][x] == '1')
            return (0);
        i = correct_move(game, x, y);
        if (!i)
            return (0);
        game->map[y][x - 1] = '0';
    }
    ft_printf("Movements: %i\n", game->counter);
    ft_printf("Collectables left: %i\n", game->collectables);
    return (1);
}

// Esta función chequea qué tecla estamos presionando y ejecuta 
// la función correspondiente
//
int controls_game(int command, t_game *game)
{
    int moving;

    moving = 0;
    if (command == 53)
        exit_game(game);
    if (command == 13)
        moving = move_up(game, command);
    if (command == 1)
        moving = move_down(game, command);
    if (command == 0)
        moving = move_left(game, command);
    if (command == 2)
        moving = move_right(game, command);
    if (moving)
        add_graphics_to_map(game);
    return (1);   
}