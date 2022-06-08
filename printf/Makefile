# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguerre <caguerre@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:07:21 by caguerre          #+#    #+#              #
#    Updated: 2022/06/08 14:20:10 by caguerre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- NAME ------------------------------------ #

NAME		= libftprintf.a

# ------------------------------- DIRECTORIES -------------------------------- #

SRCS_DIR	= sources
INC_DIR		= include
LIBS_DIR	= libft
OBJS_DIR	= objects

# --------------------------------- COLORS ----------------------------------- #

DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m

# ---------------------------------- FILES ----------------------------------- #

LIBS		= $(LIBS_DIR) /libft.a
LIBS_HDRS	= -I $(LIBS_DIR) /include/

SRCS		= ft_printf.c ft_print_char.c ft_print_dec.c ft_print_hexa.c /
				ft_print_hexaupper.c ft_print_ptr.c ft_print_string.c /
				ft_print_unsigned.c

INCLUDE		= -I $(INC_DIR) $(LIBS_HDRS)
DEP			= $(addsuffix .d $(basename $(OBJS)))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# -------------------------------- COMPILATE --------------------------------- #

COMPILE		= gcc -c
CFLAGS		= -Wall -Werror -Wextra -MMD $(INCLUDE)
AR			= ar -rcs
RM			= rm -rf
MKDIR		= mkdir -p
CP			= cp -f

# ---------------------------------- MAKE ------------------------------------- #

$(OBJSDIR)/%.o:$(SRCS_DIR)/%.c
			@$(MKDIR) $(dir $@)
			@$(COMPILE) $(CFLAGS) -o $@ $<
			@echo "$(GREEN)Compilando archivos... $ˆ $(DEF_COLOR)"

all:		make_libs $(NAME)

make_libs:
			@make -s -C $(LIBS_DIR)

-include %(DEP)
$(NAME):	$(OBJS) $(LIBS)
			@$(CP) $(LIBS) ./$(NAME)
			@$(LIBC) $(NAME) $(OBJS)
			@echo "$(GREEN)Creando libreria... $(NAME) $(DEF_COLOR)"

clean:		@make clean -s -C $(LIBS_DIR)
			@$(RM) $(OBJS)
			@$(RM) $(DEP)
			@$(RM) $(OBJS_DIR)
			@echo "$(RED)Borrando objetos... $(DEF_COLOR)

fclean:		clean
			@make fclean -s -C $(LIBS_DIR)
			@$(RM) $(NAME)
			@echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:			fclean all

.PHONY		all clean fclean re make_libs
