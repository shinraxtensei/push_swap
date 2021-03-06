NAME = push_swap

BONUS = checker

SRCS = src/push_swap.c src/utils/args_checker.c src/utils/args_handler.c \
		src/utils/stack_handler.c src/utils/sort_handler.c src/utils/small_sort.c \
		src/utils/small_sort_utils.c src/utils/big_sort_utils.c  src/utils/big_sort.c \
		src/utils/actions/push.c src/utils/actions/swap.c src/utils/actions/rotate.c \
		src/utils/actions/reverse_rotate.c \
		
SRCS_BONUS =    gnl/get_next_line_utils.c gnl/get_next_line.c src/checker.c \
				src/utils/args_checker.c src/utils/args_handler.c \
				src/utils/stack_handler.c src/utils/sort_handler.c src/utils/small_sort.c \
				src/utils/small_sort_utils.c src/utils/big_sort_utils.c  src/utils/big_sort.c \
				src/utils/actions/push.c src/utils/actions/swap.c src/utils/actions/rotate.c \
				src/utils/actions/reverse_rotate.c \

OBJS	= $(SRCS:.c=.o)

OBJS_BONS = $(SRCS_BONUS:.c=.o)

LIBFT = libft/libft.a

HEADER = src/push_swap.h


CFLAGS = -Wall -Wextra -Werror

all : $(LIBFT) $(NAME) $(HEADER)

$(NAME): $(SRCS) $(OBJS) $(HEADER)
		@gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $@
		@echo ------------------------------------
		@echo ----------- R E A D Y --------------
		@echo ------------------------------------

bonus : $(LIBFT) $(SRCS_BONUS) $(OBJS_BONS) $(HEADER)
		@gcc $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(BONUS)
		@echo ------------------------------------
		@echo ----------- R E A D Y --------------
		@echo ------------------------------------

$(LIBFT):
	@Make -C ./libft

clean :
		@Make clean -C ./libft
		@rm -rf $(OBJS) $(OBJS_BONS)

fclean :
		@Make fclean -C ./libft
		@rm -rf $(OBJS) $(OBJS_BONS) $(NAME) $(BONUS)

re :
	@Make fclean all


.PHONY : all clean fclean re