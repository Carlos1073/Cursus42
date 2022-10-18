/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:46:52 by caguerre          #+#    #+#             */
/*   Updated: 2022/05/26 11:51:16 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*element;

	if (!lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		element = ft_lstnew(tmp);
		if (!element)
		{
			del(tmp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&newlst, element);
			lst = lst->next;
		}
	}
	return (newlst);
}
