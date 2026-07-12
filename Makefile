NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

PRINTF_DIR	=	printf/printfKO
PRINTF_LIB	=	$(PRINTF_DIR)/libftprintf.a

SRC			=	main.c \
				ps_list.c \
				push_swap_atoi.c \
				push_swap_rotation1.c \
				push_swap_rotation2.c \
				push_swap_rrr.c \
				push_swap_parse.c \
				push_swap_utils.c \
				push_swap_sorting.c \
				push_swap_small.c

OBJ			=	$(SRC:.c=.o)

all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re