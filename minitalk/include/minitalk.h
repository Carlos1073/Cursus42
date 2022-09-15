/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:36:58 by caguerre          #+#    #+#             */
/*   Updated: 2022/06/13 12:37:08 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/signal.h>
# include "../libft/libft.h"

# define ERROR_0	(int)0
# define ERROR_1	(int)1
# define ERROR_2	(int)2
# define ERROR_3	(int)3

int	ft_printf(char const *str, ...);
int	ft_atoi(const char *str);
int	ft_simpletxt(char c);

#endif
