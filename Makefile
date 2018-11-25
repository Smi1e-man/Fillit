NAME = fillit

SRCS = main.c block.c list.c gnl/get_next_line.c algorithm.c

INCL = ./gnl/libft/libft.a

all: $(NAME)

$(NAME):
		gcc -g $(SRCS) $(INCL) -o $(NAME)

clean:
		rm fillit

m: clean all