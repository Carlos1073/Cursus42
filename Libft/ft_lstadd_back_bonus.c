/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:56:50 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/25 12:55:55 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*res;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		res = *lst;
		while (res->next != NULL)
			res = res->next;
		res->next = new;
	}
}
