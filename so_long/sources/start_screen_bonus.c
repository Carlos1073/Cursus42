/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/12/01 14:00:50 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

// Esta función gestiona la destrucción de la ventana de presentación y crea 
// la del juego
//
static int	loop_hook(t_game *game)
{
	if (game->start == 1)
	{
		mlx_destroy_image(game->mlx_ptr, game->initgame);
		mlx_destroy_window(game->mlx_ptr, game->screen_ptr);
		game->mlx_ptr = mlx_init();
		game->win_ptr = mlx_new_window(game->mlx_ptr, (game->widthmap * 50),
				(game->heightmap * 50), "SoLong");
		add_images_to_game(game);
		add_graphics_to_map(game);
		mlx_hook(game->win_ptr, 2, 0, controls_game, game);
		mlx_hook(game->win_ptr, 17, 0, (void *)exit, 0);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 10, 0XFFAA4D,
			ft_strjoin("Movements:", ft_itoa(game->counter)));
		mlx_loop(game->mlx_ptr);
		game->start = 0;
	}
	return (0);
}

// Con esta función controlamos los eventos mientras tenemos la pantalla de  
// presentación, de modo que si hay ESC o Space BAR, avancemos en el juego.
//
static int	start_game(int command, t_game *game)
{
	int	moving;

	moving = 0;
	if (command == 53)
		exit_game(game);
	if (command == 49)
		game->start = 1;
	return (0);
}

// Esta función inicia la ventana de presentación y utiliza las funciones
// start_game y loop_hook para poder acceder a la pantalla del juego, donde
// cargaremos el mapa.
//
void	init_game(t_game *game)
{
	int	i;
	int	j;

	game->start = 0;
	game->mlx_ptr = mlx_init();
	game->screen_ptr = mlx_new_window(game->mlx_ptr, 700, 463, "SoLong");
	game->initgame = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/screen.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx_ptr, game->screen_ptr,
		game->initgame, 0, 0);
	mlx_hook(game->screen_ptr, 2, 0, start_game, game);
	mlx_hook(game->screen_ptr, 17, 0, (void *)exit, game);
	mlx_loop_hook(game->mlx_ptr, loop_hook, game);
	mlx_loop(game->mlx_ptr);
}
