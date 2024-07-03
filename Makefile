CC=cc
CCFLAGS=-Wall -Wextra -Werror -g
NAME=push_swap
NAME_BONUS=checker
SRC_PATH=src/
SRCS_NAMES= push_swap_commands.c push_swap_calculate_moves.c stack_functions2.c \
push_swap_main_functions.c push_swap_init.c \
push_swap_push_all_sorted_aux.c stack_functions.c
SRCS=$(addprefix $(SRC_PATH), $(SRCS_NAMES))
SRCS_NAMES_BONUS= checker_bonus.c push_swap_commands.c stack_functions2.c \
push_swap_init.c stack_functions.c
SRCS_BONUS=$(addprefix $(SRC_PATH), $(SRCS_NAMES))
OBJ_PATH=build/
OBJS_NAMES=$(SRCS_NAMES:.c=.o)
OBJS=$(addprefix $(OBJ_PATH), $(OBJS_NAMES))
OBJS_NAMES_BONUS=$(SRCS_NAMES_BONUS:.c=.o)
OBJS_BONUS=$(addprefix $(OBJ_PATH), $(OBJS_NAMES_BONUS))
LIBS=-lft
LIB_PATH=-L lib
INCLUDE_PATH=./include/ ./lib/*/include/
INCLUDE=$(addprefix -I , $(INCLUDE_PATH))
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make all -C lib/libft
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE) $(LIB_PATH) $(LIBS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make all -C lib/libft
	$(CC) $(CCFLAGS) $(OBJS_BONUS) $(INCLUDE) $(LIB_PATH) $(LIBS) -o $(NAME_BONUS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	make clean -C lib/libft
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C lib/libft
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_BONUS)
	norminette -R CheckDefine $(INCLUDE_PATH)*.h

run:
	./push_swap $(ARGS)

.PHONY=all bonus clean fclean re norm run
