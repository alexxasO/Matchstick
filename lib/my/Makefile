##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## build the lib
##

SRC	=	concat_params.c 	\
		flags.c 	\
		get_color.c 	\
		main.c 	\
		my_compute_power_rec.c 	\
		my_compute_square_root.c 	\
		my_find_prime_sup.c 	\
		my_getnbr.c 	\
		my_is_prime.c 	\
		my_printf.c 	\
		my_putchar.c 	\
		my_put_long_nbr.c 	\
		my_putnbr_base.c 	\
		my_putnbr_base_unsigned.c 	\
		my_put_nbr.c 	\
		my_putnbr_count.c 	\
		my_put_nbr_unsigned.c 	\
		my_putstr.c 	\
		my_revstr.c 	\
		my_showstr.c 	\
		my_show_word_array.c 	\
		my_sort_int_array.c 	\
		my_strcat.c 	\
		my_strcmp.c 	\
		my_strcpy.c 	\
		my_strdup.c 	\
		my_str_isalpha.c 	\
		my_str_islower.c 	\
		my_str_isnum.c 	\
		my_str_isprintable.c 	\
		my_str_isupper.c 	\
		my_strlen.c 	\
		my_strlowcase.c 	\
		my_strncat.c 	\
		my_strncmp.c 	\
		my_strncpy.c 	\
		my_str_to_word_array.c 	\
		my_strupcase.c 	\
		my_swap.c	\
		str_contain.c


OBJ	=	$(SRC:.c=.o)

MY	=	my.h

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ) $(SRC)
	@ar -crs $(NAME) $(OBJ)
	cp $(NAME) ../

.PHONY: clean re fclean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re :	fclean all

tests_run :
	make -f Makefile_test
