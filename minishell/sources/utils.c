/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:02:23 by caguerre          #+#    #+#             */
/*   Updated: 2023/04/26 16:49:30 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Imprime el mensaje sólo cuando los parámetros de entrada son incorrectos,
// enviando al fd stderr la string que debe printear.
//
bool    print_message(bool return_val)
{
    ft_putendl_fd("Usage: ./minishell", 2);
    ft_putendl_fd("Usage: ./minishell -c \"input line\"", 2);
    return (return_val);
}