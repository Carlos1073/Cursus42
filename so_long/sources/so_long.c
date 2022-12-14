/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:39 by caguerre          #+#    #+#             */
/*   Updated: 2022/12/01 14:00:50 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Esta función verifica que el mapa tiene la extension BER
//
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

// Esta función cierra la ventana, libera tanto el puntero como el mapa
// y sale del programa
//
int	exit_game(t_game *game)
{
	int	i;

	i = 0;
	purge_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_printf("\nExiting game...\n");
	exit(0);
}

// Con esta función hacemos el check del mapa, para saber si los muros están
// perfectamente cerrados y si están todos los items que requiere el juego 
// para poder funcionar. Luego localizamos la posición del Player y hacemos 
// una copia del mapa para verificar que hay un path válido
//
void	check_errors(t_game *game)
{
	check_walls(game);
	check_items(game);
	get_player_position(game);
	game->map_tmp = copying_map(game);
	if (!game->map_tmp)
		ft_errors(game, ERROR_6);
	if (!check_path_to_exit(game, game->player_y, game->player_x))
		ft_errors(game, ERROR_6);
}

// Función principal. Primero chequeamos argumentos y que el mapa que vamos
// a cargar no tenga errores básicos 
//
int	main(int argc, char **argv)
{
	int		i;
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
	check_errors(&game);
	init_game(&game);
}
