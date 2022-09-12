# ---------------------------------- NAME ------------------------------------ #

NAME				= minitalk
NAME_BONUS			= minitalk_bonus
NAME_CLIENT			= client
NAME_SERVER			= server
NAME_CLIENTBONUS	= client_bonus
NAME_SERVERBONUS	= server_bonus

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
CLIENTBONUS_SRCS = client_bonus.c
SERVERBONUS_SRCS = server_bonus.c

SRCS_CLIENT += $(addprefix $(SRCS_DIR), $(CLIENT_SRCS))
SRCS_SERVER += $(addprefix $(SRCS_DIR), $(SERVER_SRCS))

OBJS_CLIENT = $(addprefix $(OBJS_DIR), $(CLIENT_SRCS:.c=.o))
OBJS_SERVER = $(addprefix $(OBJS_DIR), $(SERVER_SRCS:.c=.o))

DEP_CLIENT = $(addsuffix .d, $(basename $(OBJS_CLIENT)))
DEP_SERVER = $(addsuffix .d, $(basename $(OBJS_SERVER)))

SRCS_CLIENTBONUS += $(addprefix $(SRCS_DIR), $(CLIENTBONUS_SRCS))
SRCS_SERVERBONUS += $(addprefix $(SRCS_DIR), $(SERVERBONUS_SRCS))

OBJS_CLIENTBONUS = $(addprefix $(OBJS_DIR), $(CLIENTBONUS_SRCS:.c=.o))
OBJS_SERVERBONUS = $(addprefix $(OBJS_DIR), $(SERVERBONUS_SRCS:.c=.o))

DEP_CLIENTBONUS = $(addsuffix .d, $(basename $(OBJS_CLIENTBONUS)))
DEP_SERVERBONUS = $(addsuffix .d, $(basename $(OBJS_SERVERBONUS)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar -rcs
CP		= cp -f
MKDIR	= mkdir -p

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@echo "$(GREEN)Compilando archivos... $^ $(DEF_COLOR)"
	$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all:	make_libs $(NAME_CLIENT) $(NAME_SERVER)

bonus:	make_libs $(NAME_CLIENTBONUS) $(NAME_SERVERBONUS)

$(NAME): make_libs $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)
	@echo "$(GREEN) Client compilado!$(DEF_COLOR)"

$(NAME_SERVER): $(OBJS_SERVER) $(HDRS)	
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)
	@echo "$(GREEN) Server compilado!$(DEF_COLOR)"
	@touch $@

$(NAME_CLIENTBONUS): $(OBJS_CLIENTBONUS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS_CLIENTBONUS) $(LIBS) -o $(NAME_CLIENTBONUS)
	@echo "$(GREEN) Client compilado!$(DEF_COLOR)"

$(NAME_SERVERBONUS): $(OBJS_SERVERBONUS) $(HDRS)	
	$(CC) $(CFLAGS) $(OBJS_SERVERBONUS) $(LIBS) -o $(NAME_SERVERBONUS)
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
	@$(RM) $(NAME) $(NAME_BONUS) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENTBONUS) $(NAME_SERVERBONUS)
	@echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:			fclean all

-include $(DEP)

.PHONY:		all clean fclean re make_libs
