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
		ft_printf("%sWarning: Invalid parameters!\n", YEL);
	else if (i == ERROR_1)
		ft_printf("%sWarning: Invalid walls!\n", YEL);
	else if (i == ERROR_2)
		ft_printf("%sWarning: Problem with player, collectable or exit!\n", YEL);
	else if (i == ERROR_3)
		ft_printf("%sError!\n", RED);
	else if (i == ERROR_4)
		ft_printf("%sWarning: Can't open the map!\n", YEL);
	else if (i == ERROR_5)
		ft_printf("%sWarning: It's not a rectangle!\n", YEL);
	else if (i == ERROR_6)
		ft_printf("%sWarning: Map with invalid path!\n", YEL);
	else if (i == ERROR_7)
		ft_printf("%sWarning: The map is empty!\n", YEL);
	exit_game(game);
}
