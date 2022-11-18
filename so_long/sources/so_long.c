/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:41 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Esta función verifica que el mapa tiene la extension BER
//
// int	check_extension(t_game *game, char *filename)
int	check_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (!ft_strnstr(&filename[len - 4], ".ber", 4))
    {
	    ft_printf("Error: This is not a BER file!\n");
		return (-1);
	}
	return (0);
}

// Esta función cierra la ventana, libera el mapa y sale del programa
//
int	exit_game(t_game *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

// Con esta función hacemos el check del mapa, para saber si los muros están
// perfectamente cerrados y si están todos los items que requiere el juego 
// para poder funcionar
//
void	check_errors(t_game *game)
{
	check_walls(game);
	check_items(game);
}

// Función principal. Primero chequeamos argumentos y que el mapa que vamos
// a cargar no tenga errores básicos,  
//
int main(int argc, char **argv)
{
	int		i;
	// int		j;
	t_game	game;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error: Invalid parameters!\n");
		return (0);
	}
	if (check_extension(argv[1]) == -1)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	reading_map(&game, argv);
	// if (game.map != NULL)
	// {
	// 	while (game.map[i])
	// 	{
	// 		j = 0;
	// 		while (game.map[i][j])
	// 		{
	// 			printf("%c", game.map[i][j]);
	// 			j++;
	// 		}
	// 		i++;
	// 	}
	// }
	check_errors(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.widthmap * 50), (game.heightmap * 50), "SoLong");
	add_images_to_game(&game);
	add_graphics_to_map(&game);
	// mlx_key_hook (game.win_ptr, controls_game, &game);
	mlx_hook(game.win_ptr, 2, 0, controls_game, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
}