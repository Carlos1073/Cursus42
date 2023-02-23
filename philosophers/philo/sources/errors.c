/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:13 by caguerre          #+#    #+#             */
/*   Updated: 2023/02/15 16:37:47 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_errors(int i)
{

	if (i == ERROR_0)
		printf(YELLOW "Warning: Incorrect number of parameters!\n" WHITE);
	else if (i == ERROR_1)
		printf(YELLOW "Warning: There are no philosophers!\n" WHITE);
    else if (i == ERROR_2)
		printf(YELLOW "Warning: There are one or more invalid numbers!\n" WHITE);
}