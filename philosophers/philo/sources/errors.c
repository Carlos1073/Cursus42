/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:13 by caguerre          #+#    #+#             */
/*   Updated: 2023/04/13 10:36:22 by caguerre         ###   ########.fr       */
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
	else if (i == ERROR_3)
		printf(YELLOW "Warning: There are no number of meals!\n" WHITE);
}
