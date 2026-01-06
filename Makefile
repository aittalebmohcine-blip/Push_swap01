NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I. -I$(LIBFT_DIR)

SRCS        = push_swap.c \
              ft_spaces_split.c \
              set_stacka_orexit.c \
              set_tokens_orexit.c \
              stack_hasdup_exit.c \
              tokenize.c \
              tokens_to_stack_free.c \
              utils.c \
              validate_tokens.c \
              stack_is_sorted_exit.c \
              swap_utils.c\
              push.c\
							rotate.c\
							reverse_rotate.c\
							sorting_algo.c\

OBJS        = $(SRCS:.c=.o)

# -------------------------------- RULES ------------------------------------ #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c libpushswap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
