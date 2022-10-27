/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:58:58 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/28 15:24:33 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*new;

	new = begin_list;
	if ((*cmp)(new->data, data_ref) == 0)
	{
		*begin_list = new->next;
		free(new);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	new = *begin_list;
	ft_list_remove_if(&new->next, data_ref, cmp);
}
