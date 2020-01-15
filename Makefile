##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c		\
			src/matches.c 	\
			src/map.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/my
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L./lib -lmy

clean:
	make -C lib/my clean
	$(RM) $(OBJS)

fclean: clean
	make -C lib/my fclean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re
