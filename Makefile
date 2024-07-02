CC=cc
CCFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs
NAME=push_swap
SRC_PATH=./src
SRCS= push_swap_commands.c push_swap_calculate_moves.c stack_functions2.c \
push_swap_main_functions.c push_swap_init.c \
push_swap_push_all_sorted_aux.c stack_functions.c
OBJS=$(SRCS:.c=.o)
OBJ_PATH=./build
LIBS=-lft
LIB_PATH=lib
INCLUDE=./include
RM=rm -f


all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C libft
	mv lib/libft/libft.a lib/
	$(CC) $(CCFLAGS) $(OBJS) -I $(INCLUDE) -L $(LIB_PATH) $(LIBS) -o $(NAME)

bonus: all

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $(OBJ_PATH)/$@ -I $(INCLUDE)

clean:
	make clean -C libft
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all
