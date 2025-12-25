Name = push_swap
SRC = push_swap.c
OBJ = $(SRC:.c=.o)

$(Name):libft/libft.a $(OBJ)
	cc -o $(Name) $(OBJ) libft/libft.a

#
#cc push_swap.o libft.a
%.o : %.c $(HEADER)
	cc -c $(OBJ)
