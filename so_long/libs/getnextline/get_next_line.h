/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:06:57 by caguerre          #+#    #+#             */
/*   Updated: 2022/07/01 16:27:31 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd);
char	*ft_get_line(char *storage);
char	*ft_save(char *storage, int c);
char	*ft_read_save(int fd, char *storage);
char	*ft_stringjoin(char *s1, char *s2);
char	*ft_stringchr(char *s, int c);
size_t	ft_stringlen(char *str);
char	*ft_stringdup(char *s1);

#endif
