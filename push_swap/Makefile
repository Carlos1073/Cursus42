# ---------------------------------- NAME ------------------------------------ #

NAME		= push_swap

# ------------------------------- DIRECTORIES -------------------------------- #

SRCS_DIR	= sources/
INC_DIR		= include/
LIBS_DIR	= libft/
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

LIBS = $(LIBS_DIR)libft.a
INCLUDE = -I $(INC_DIR)
HDRS = $(INC_DIR)push_swap.h

NAME_SRCS = 3_numbers.c calculate_cost.c check_arg_utils.c check_arg.c init_stacks.c \
		many_numbers.c ops_move.c ops_push.c ops_rotate1.c ops_rotate2.c ops_swap.c \
		position.c push_swap.c stack_utils.c utils.c

SRCS_NAME += $(addprefix $(SRCS_DIR), $(NAME_SRCS))

OBJS_NAME = $(addprefix $(OBJS_DIR), $(SRCS_NAME:.c=.o))

DEP_NAME = $(addsuffix .d, $(basename $(OBJS_NAME)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
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

#$(NAME): make_libs $(NAME)

$(NAME): $(OBJS_NAME)
	$(CC) $(CFLAGS) $(OBJS_NAME) $(LIBS) -o $(NAME)
	@echo "$(GREEN) Programa compilado!$(DEF_COLOR)"

make_libs:
	@make -C $(LIBS_DIR) 

clean:		
	@make clean -s -C $(LIBS_DIR)
	@$(RM) $(DEP)
	@$(RM) -r $(OBJS_NAME) $(OBJS_DIR)
	@echo "$(RED)Borrando objetos... $(DEF_COLOR)"

fclean:		clean
	@make fclean -s -C $(LIBS_DIR)
	@$(RM) $(NAME)
	@echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re make_libs
