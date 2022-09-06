# ---------------------------------- NAME ------------------------------------ #

NAME		= minitalk
NAME_CLIENT	= client
NAME_SERVER	= server

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
HDRS = $(INC_DIR)minitalk.h

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

SRCS_CLIENT += $(addprefix $(SRCS_DIR), $(CLIENT_SRCS))
SRCS_SERVER += $(addprefix $(SRCS_DIR), $(SERVER_SRCS))

OBJS_CLIENT = $(addprefix $(OBJS_DIR), $(CLIENT_SRCS:.c=.o))
OBJS_SERVER = $(addprefix $(OBJS_DIR), $(SERVER_SRCS:.c=.o))

#OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)
#OBJS_SERVER = $(SERVER_SRCS:.c=.o)

DEP_CLIENT = $(addsuffix .d, $(basename $(OBJS_CLIENT)))
DEP_SERVER = $(addsuffix .d, $(basename $(OBJS_SERVER)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar -rcs
CP		= cp -f
MKDIR	= mkdir -p

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(HDRS) Makefile
	@$(MKDIR) $(dir $@)
	@echo "$(GREEN)Compilando archivos... $^ $(DEF_COLOR)"
	$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all:	make_libs $(NAME)

$(NAME): $(OBJS_CLIENT) $(OBJS_SERVER) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)
	@echo "$(GREEN) Client compilado!$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)
	@echo "$(GREEN) Server compilado!$(DEF_COLOR)"
	@touch $@

make_libs:
	@make -C $(LIBS_DIR)

clean:		
	@make clean -s -C $(LIBS_DIR)
	@$(RM) $(DEP)
	@$(RM) -r $(OBJS_DIR)
	@echo "$(RED)Borrando objetos... $(DEF_COLOR)"

fclean:		clean
	@make fclean -s -C $(LIBS_DIR)
	@$(RM) $(NAME) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:			fclean all

-include $(DEP)

.PHONY:		all clean fclean re make_libs
