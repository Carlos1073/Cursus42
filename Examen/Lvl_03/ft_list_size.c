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

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}
// {
// 	t_list	*list;
// 	int		i;

// 	i = 0;
// 	list = begin;
// 	while (list)
// 	{
// 		list = list->next;
// 		i++;
// 	}
// 	return (i);
// }
