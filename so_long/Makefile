# ---------------------------------- NAME ------------------------------------ #

NAME		= so_long
NAME_BONUS	= so_long_bonus

# ------------------------------- DIRECTORIES -------------------------------- #

SRCS_DIR		= sources/
INC_DIR			= include/
LIBFT_DIR		= libs/libft/
MINILIBX_DIR	= libs/minilibx/
GNL_DIR			= libs/getnextline/
OBJS_DIR		= objects/

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

LIBS = $(LIBFT_DIR)libft.a $(MINILIBX_DIR)libmlx.a $(GNL_DIR)libgnl.a

LIBPATH = -Llibs/minilibx -Llibs/getnextline -Llibs/libft

LDLIBS = -lmlx -lgnl -lft

INCLUDE = -I $(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR) -I $(MINILIBX_DIR)$(INC_DIR) -I $(GNL_DIR)$(INC_DIR)

HDRS = $(INC_DIR)so_long.h $(LIBS)

NAME_SRCS = check_parameters.c errors.c so_long.c map.c images.c controls.c moving.c check_path.c start_screen.c

NAME_BONUS_SRCS = check_parameters_bonus.c errors_bonus.c so_long_bonus.c map_bonus.c images_bonus.c controls_bonus.c moving_bonus.c check_path_bonus.c start_screen_bonus.c

SRCS_NAME = $(addprefix $(SRCS_DIR), $(NAME_SRCS))

SRCS_NAME_BONUS = $(addprefix $(SRCS_DIR), $(NAME_BONUS_SRCS))

OBJS_NAME = $(addprefix ., $(NAME_SRCS:.c=.o))

OBJS_NAME_BONUS = $(addprefix ., $(NAME_BONUS_SRCS:.c=.o))

DEP_NAME = $(addsuffix .d, $(basename $(OBJS_NAME)))

DEP_NAME_BONUS = $(addsuffix .d, $(basename $(OBJS_NAME_BONUS)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -MMD
RM		= rm -f
AR		= ar -rcs
CP		= cp -f
MKDIR	= mkdir -p

# --------------------------------- RULES ------------------------------------ #

.%.o: $(SRCS_DIR)%.c Makefile
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@
	@echo "$(GREEN)Compilando archivos... $^ $(DEF_COLOR)"

all:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) $(NAME)

bonus:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) $(NAME_BONUS)

-include $(DEP_NAME)
$(NAME): $(OBJS_NAME) $(HDRS) 
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(OBJS_NAME) $(LIBPATH) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN) Programa compilado!$(DEF_COLOR)"

-include $(DEP_NAME_BONUS)
$(NAME_BONUS): $(OBJS_NAME_BONUS) $(HDRS) 
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(OBJS_NAME_BONUS) $(LIBPATH) $(LDLIBS) -o $(NAME_BONUS)
	@echo "$(GREEN) Programa compilado!$(DEF_COLOR)"

clean:		
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(MINILIBX_DIR)
	@make clean -s -C $(GNL_DIR)
	@$(RM) $(DEP_NAME) $(DEP_NAME_BONUS)
	@$(RM) -r $(OBJS_NAME) $(OBJS_NAME_BONUS) $(OBJS_DIR)
	@echo "$(RED)Borrando objetos... $(DEF_COLOR)"

fclean:		clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re make_libs
