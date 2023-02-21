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
	t_list	*lst;
	t_list	*tmp;

	lst = *begin_list;
	while (lst && !cmp(data_ref, lst->data))
	{
		*begin_list = (*begin_list)->next;
		free(lst);
		lst = *begin_list;
	}
	while (lst)
	{
		if (lst->next && !cmp(data_ref, lst->next->data))
		{
			tmp = lst->next;
			lst->next = lst->next->next;
			free (tmp);
		}
		else
			lst = lst->next;
	}
}
