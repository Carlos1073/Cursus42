/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:55:58 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/27 10:59:54 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		i;

	i = 0;
	list = begin;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
