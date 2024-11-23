CC = gcc

CFLAGS = -Wall -Wextra

SRC = main.c loc.c map.c moves.c queue.c stack.c tree.c

OBJS = $(SRC:.c=.o)

NAME = marc

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@
		rm -rf $(OBJS)

clean:
		rm -f $(NAME)
		rm -rf $(OBJS)
		rm -rf a.out

re: clean all

.PHONY: all clean re
