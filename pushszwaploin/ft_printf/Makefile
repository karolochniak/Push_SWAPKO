NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_printf.c \
parse.c \
parse_utils.c \
convert_char_str_percent.c \
convert_int.c \
convert_uint.c \
convert_hex.c \
convert_ptr.c \
format_output.c \
utils_io.c \
utils_num.c \
utils_misc.c \
hex_utils.c \
utils_int.c

LIBSRC = libft/ft_atoi.c \
libft/ft_bzero.c \
libft/ft_isalnum.c \
libft/ft_isalpha.c \
libft/ft_isascii.c \
libft/ft_isdigit.c \
libft/ft_isprint.c \
libft/ft_itoa.c \
libft/ft_strlen.c \
libft/ft_memchr.c \
libft/ft_memcmp.c \
libft/ft_memcpy.c \
libft/ft_memmove.c \
libft/ft_memset.c \
libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c \
libft/ft_split.c \
libft/ft_strchr.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c \
libft/ft_strdup.c \
libft/ft_striteri.c \
libft/ft_strjoin.c \
libft/ft_strlcat.c \
libft/ft_strlcpy.c \
libft/ft_strmapi.c \
libft/ft_tolower.c \
libft/ft_toupper.c \
libft/ft_strncmp.c \
libft/ft_strnstr.c \
libft/ft_strrchr.c \
libft/ft_strtrim.c \
libft/ft_substr.c \
libft/ft_calloc.c \
libft/ft_lstdelone_bonus.c \
libft/ft_lstnew_bonus.c \
libft/ft_lstsize_bonus.c \
libft/ft_lstadd_back_bonus.c \
libft/ft_lstadd_front_bonus.c \
libft/ft_lstclear_bonus.c \
libft/ft_lstiter_bonus.c \
libft/ft_lstlast_bonus.c \
libft/ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIBSRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): lib $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBOBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

lib:
	$(MAKE) -C libft

clean:
	rm -f $(OBJ) $(BOBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean lib fclean re bonus
