#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR_0	(int)0
# define ERROR_1	(int)1
# define ERROR_2	(int)2
# define ERROR_3	(int)3
# define ERROR_4	(int)4
# define ERROR_5	(int)5
# define ERROR_7	(int)7

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
#include <limits.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/getnextline/get_next_line.h"

typedef struct t_start
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
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

	void	*indy_w;
	void	*indy_s;
	void	*indy_a;
	void	*indy_d;
	void	*exit;
	void	*floor;
	void	*stone;
	void	*idol;

}	t_game;

int		exit_game(t_game *game);
void	check_errors(t_game *game);
void	ft_errors(t_game *game, int i);
void    check_walls(t_game *game);
void    check_items(t_game *game);
int 	reading_map(t_game *game, char **argv);
void    add_images_to_game(t_game *game);
void    add_graphics_to_map(t_game *game);
int 	controls_game(int command, t_game *game);
int		correct_move(t_game *game, int i, int j);

#endif
