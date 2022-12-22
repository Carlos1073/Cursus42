/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR_0	(int)0
# define ERROR_1	(int)1
# define ERROR_2	(int)2
# define ERROR_3	(int)3
# define ERROR_4	(int)4
# define ERROR_5	(int)5
# define ERROR_6	(int)6
# define ERROR_7	(int)7

# define IS_TRUE 1
# define IS_FALSE 0

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define WHT	"\x1B[37m"
# define CYN	"\x1B[36m"
# define MGT "\033[0;95m"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/getnextline/get_next_line.h"

typedef struct t_start
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*screen_ptr;
	char	**map;
	char	**map_tmp;
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		collectables;
	int		wall;
	int		player_x;
	int		player_y;
	int		counter;
	int		keymove;
	int		reachable_collectables;
	int		reachable_exit;
	int		start;
	int		pid;

	void	*indy_w;
	void	*indy_s;
	void	*indy_a;
	void	*indy_d;
	void	*exit;
	void	*floor;
	void	*stone;
	void	*idol;
	void	*initgame;

}	t_game;

int		exit_game(t_game *game);
void	check_errors(t_game *game);
void	ft_errors(t_game *game, int i);
void	check_walls(t_game *game);
void	check_items(t_game *game);
int		reading_map(t_game *game, char **argv);
void	add_images_to_game(t_game *game);
void	add_graphics_to_map(t_game *game);
int		controls_game(int command, t_game *game);
int		correct_move(t_game *game, int i, int j);
bool	check_path_to_exit(t_game *game, int y, int x);
void	get_player_position(t_game *game);
char	**copying_map(t_game *game);
void	purge_images(t_game *game);
void	init_game(t_game *game);

#endif
