##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re
