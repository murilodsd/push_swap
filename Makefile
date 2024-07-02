CC=cc
CCFLAGS=-Wall -Wextra -Werror
NAME=push_swap
SRC_PATH=src/
SRCS_NAMES= push_swap_commands.c push_swap_calculate_moves.c stack_functions2.c \
push_swap_main_functions.c push_swap_init.c \
push_swap_push_all_sorted_aux.c stack_functions.c
SRCS=$(addprefix $(SRC_PATH), $(SRCS_NAMES))
OBJ_PATH=build/
OBJS_NAMES=$(SRCS_NAMES:.c=.o)
OBJS=$(addprefix $(OBJ_PATH), $(OBJS_NAMES))
LIBS=-lft
LIB_PATH=-L lib
INCLUDE=-I ./include -I ./lib/libft/
RM=rm -f


all: $(NAME)

$(NAME): $(OBJS)
	make all -C lib/libft
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE) $(LIB_PATH) $(LIBS) -o $(NAME)

bonus: all

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	make clean -C lib/libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C lib/libft
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCS)

run: all
	./push_swap $(ARGS)

checker:
	./push_swap $(ARGS) | ./checker_linux $(ARGS)

git:
	git add .
	git commit -m"$(MSG)"
	git push

.PHONY=all bonus clean fclean re norm
