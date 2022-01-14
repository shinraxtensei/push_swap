NAME = push_swap

SRCS = src/push_swap.c src/utils/args_checker.c src/utils/args_handler.c \
		src/utils/stack_handler.c src/utils/sort_handler.c src/utils/small_sort.c \
		src/utils/small_sort_utils.c src/utils/big_sort_utils.c  src/utils/big_sort.c \
		src/utils/actions/push.c src/utils/actions/swap.c src/utils/actions/rotate.c \
		src/utils/actions/reverse_rotate.c

OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a

HEADER = src/push_swap.h

CFLAGS = -Wall -Wextra -Werror

all : $(LIBFT) $(NAME) $(HEADER)

$(NAME): $(SRCS) $(OBJS) $(HEADER)
		@gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $@
		@echo -------------ready------------------

$(LIBFT):
	@Make -C ./libft

clean :
		@Make clean -C ./libft
		@rm -rf $(OBJS)

fclean :
		@Make fclean -C ./libft
		@rm -rf $(OBJS) $(NAME)

re :
	fclean all

.PHONY : all clean fclean re