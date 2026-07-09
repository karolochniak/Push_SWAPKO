NAME		=	push_swap
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I.
FT_PRINTF_DIR	=	./ft_printf
FT_PRINTF_LIB	=	$(FT_PRINTF_DIR)/libftprintf.a

SRCS	=	push_swap.c \
		parse_arguments.c \
		char_utils.c \
		vector.c \
		array_utils.c \
		stack_init.c \
		stack_pop.c \
		node.c \
		build_stack.c \
		operations_swap.c \
		operations_push.c \
		rotate_up.c \
		rotate_down.c \
		check_sorted.c \
		sort_dispatch.c \
		sort_three.c \
		sort_small.c \
		sort_radix.c \
		cleanup.c \
		error.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean
	$(MAKE)

.PHONY:	all clean fclean re
