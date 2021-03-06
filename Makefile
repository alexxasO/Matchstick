##
## EPITECH PROJECT, 2019
## PSU_minishell1_2019
## File description:
## Makefile
##

ECHO =		/bin/echo -e
DEFAULT =	"\033[00m"
GREEN =		"\033[0;32m"
BGREEN =	"\033[1;32m"
TEAL =		"\033[1;36m"
ORANGE =	"\e[1;33m"
RED =		"\033[0;31m"
BRED =		"\033[1;31m"
FLASH = 	"\e[5;30m"
BYELLOW =	"\e[1;33m"
BMAGENTA =	"\e[1;95m"

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	=	src/gameplay.c	\
			src/main.c		\
			src/map.c		\
			src/matches.c

OBJS	= $(SRCS:.c=.o)

LIB = lib/libmy.a

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra
CFLAGS += -L./lib -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) && \
	$(ECHO) $(BGREEN) "Build Complete !" $(DEFAULT) \
	|| $(ECHO) $(FLASH) $(BRED) "Build Failed !" $(DEFAULT)

clean:
	@make -C lib/my clean --no-print-directory
	@$(RM) $(OBJS)
	@$(ECHO) $(BMAGENTA) "clean" $(DEFAULT)

$(LIB):
	@make -C lib/my --no-print-directory
	@$(ECHO) $(BGREEN) "Lib Complete !\n"

fclean: clean
	@make -C lib/my fclean --no-print-directory
	@$(RM) $(NAME)
	@$(ECHO) $(BMAGENTA) "fclean" $(DEFAULT)

re: fclean all

debug: CFLAGS += -g
debug: re
		@$(ECHO) $(BRED) "Debug mode"

.PHONY: all clean fclean re

.c.o:
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) \
		$(BGREEN)"[OK]"$(BYELLOW) `basename $^` $(DEFAULT) \
		|| $(ECHO) $(BRED)"[ERROR]"$(BYELLOW) $< $(DEFAULT)