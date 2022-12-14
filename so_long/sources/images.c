/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	purge_images(t_game *game)
{
	if (game->indy_w)
		mlx_destroy_image(game->mlx_ptr, game->indy_w);
	if (game->indy_s)
		mlx_destroy_image(game->mlx_ptr, game->indy_s);
	if (game->indy_a)
		mlx_destroy_image(game->mlx_ptr, game->indy_a);
	if (game->indy_d)
		mlx_destroy_image(game->mlx_ptr, game->indy_d);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->idol)
		mlx_destroy_image(game->mlx_ptr, game->idol);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->stone)
		mlx_destroy_image(game->mlx_ptr, game->stone);
}

void	put_player(t_game *game, int height, int width)
{
	if (game->keymove == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->indy_w,
			width * 50, height * 50);
	if (game->keymove == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->indy_s,
			width * 50, height * 50);
	if (game->keymove == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->indy_a,
			width * 50, height * 50);
	if (game->keymove == 4)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->indy_d,
			width * 50, height * 50);
	if (!game->keymove)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->indy_s,
			width * 50, height * 50);
	game->player_x = width;
	game->player_y = height;
}

void	put_collectables(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->idol,
		width * 50, height * 50);
	game->collectables++;
}

// Esta función carga las imágenes en su variable correspondiente
//
void	add_images_to_game(t_game *game)
{
	int	i;
	int	j;

	game->stone = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/stone.xpm", &i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/floor.xpm", &i, &j);
	game->idol = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/idol.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/exit.xpm", &i, &j);
	game->indy_w = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/indy_up.xpm", &i, &j);
	game->indy_s = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/indy_down.xpm", &i, &j);
	game->indy_a = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/indy_left.xpm", &i, &j);
	game->indy_d = mlx_xpm_file_to_image(game->mlx_ptr,
			"sources/game_images/indy_right.xpm", &i, &j);
}

// Esta función asigna las imágenes en función de la casilla
//
void	add_graphics_to_map(t_game *game)
{
	int	width;
	int	height;

	game->collectables = 0;
	height = -1;
	while (++height < game->heightmap)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->stone, width * 50, height * 50);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->floor, width * 50, height * 50);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit, width * 50, height * 50);
			if (game->map[height][width] == 'P')
				put_player(game, height, width);
			if (game->map[height][width] == 'C')
				put_collectables(game, height, width);
		}
	}
}
