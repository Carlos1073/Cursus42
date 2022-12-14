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

// Esta función chequea qué tecla estamos presionando y ejecuta 
// la función correspondiente
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
		mlx_loop(game->mlx_ptr);
		game->start = 0;
	}
	return (0);
}

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

void	init_game(t_game *game)
{
	int i;
	int j;

	game->start = 0;
	game->mlx_ptr = mlx_init();
	game->screen_ptr = mlx_new_window(game->mlx_ptr, 700, 463, "SoLong");
	game->initgame = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/screen.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx_ptr, game->screen_ptr, game->initgame, 0, 0);
	mlx_hook(game->screen_ptr, 2, 0, start_game, game);
	mlx_hook(game->screen_ptr, 17, 0, (void *)exit, game);
	mlx_loop_hook(game->mlx_ptr, loop_hook, game);
	mlx_loop(game->mlx_ptr);
}