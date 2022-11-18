# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 11:14:18 by caguerre          #+#    #+#              #
#    Updated: 2022/06/09 12:52:57 by caguerre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a
HEADERS	= get_next_line.h

CC		= gcc
AR		= ar -rcs
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
NORM	= norminette -R CheckForbiddenSourceHeader .
SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

%.o : %.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		 $(AR) $(NAME) $(OBJS)

clean:
		@$(RM) $(OBJS)

norma = @$(NORM)

fclean:	clean
		$(RM) $(NAME)
	
re: fclean all

.PHONY : all clean fclean re