/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:18 by caguerre          #+#    #+#             */
/*   Updated: 2022/11/02 17:22:21 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_errors(t_game *game, int i)
{
	if (i == ERROR_0)
		ft_printf("Error: Invalid parameters!\n");
	else if (i == ERROR_1)
		ft_printf("Error: Invalid walls!\n");
	else if (i == ERROR_2)
		ft_printf("Error: Problem with player, collectable or exit!\n");
	else if (i == ERROR_3)
		ft_printf("Error!\n");
	else if (i == ERROR_4)
		ft_printf("Error: Can't open the map!\n");
	else if (i == ERROR_5)
		ft_printf("Error: It's not a rectangle!\n");
	else if (i == ERROR_6)
		ft_printf("Error: Map with invalid path!\n");
	else if (i == ERROR_7)
		ft_printf("Error: The map is empty!\n");
	exit_game(game);
}
