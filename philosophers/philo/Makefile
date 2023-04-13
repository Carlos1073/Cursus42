# ---------------------------------- NAME ------------------------------------ #

NAME		= philosophers

# ------------------------------- DIRECTORIES -------------------------------- #

SRCS_DIR	= sources/
INC_DIR		= include/
OBJS_DIR	= objects/

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

INCLUDE = -I $(INC_DIR)
HDRS = $(INC_DIR)philosophers.h

NAME_SRCS = philo.c utils.c check_parameters.c errors.c initialize.c launch.c exit.c

SRCS_NAME += $(addprefix $(SRCS_DIR), $(NAME_SRCS))

OBJS_NAME = $(addprefix $(OBJS_DIR), $(SRCS_NAME:.c=.o))

DEP_NAME = $(addsuffix .d, $(basename $(OBJS_NAME)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -f
AR		= ar -rcs
CP		= cp -f
MKDIR	= mkdir -p

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o: %.c Makefile
	mkdir -p $(dir $@)
	@echo "$(GREEN)Compilando archivos... $^ $(DEF_COLOR)"
	$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all:	make_libs $(NAME)

-include $(DEP_NAME)

$(NAME): $(OBJS_NAME)
	$(CC) $(CFLAGS) $(OBJS_NAME) -o $(NAME)
	@echo "$(GREEN) Programa compilado!$(DEF_COLOR)"

clean:		
	@$(RM) $(DEP_NAME)
	@$(RM) -r $(OBJS_NAME) $(OBJS_DIR)
	@echo "$(RED)Borrando objetos... $(DEF_COLOR)"

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re make_libs
