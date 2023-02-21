/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:53:51 by caguerre          #+#    #+#             */
/*   Updated: 2022/09/28 14:54:52 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIST.H
# define FT_LIST.H

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#endif
