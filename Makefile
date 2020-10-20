##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	navy

CC	=	gcc -o

CFLAGS	=	-L ./lib/my -lmy -I./include/

SRC	=	src/main.c					\
		src/games.c 				\
		src/connection.c			\
		src/utils_connection.c 		\
		src/error.c					\
		src/map.c					\
		src/get_next_line.c			\
		src/utils.c 				\
		lib/my/my_getnbr.c			\
		lib/my/my_putchar.c			\
		lib/my/my_put_nbr.c			\
		lib/my/my_putstr.c			\
		lib/my/my_getnbr_char.c		\
		lib/my/my_strlen.c			\
		lib/ptf/my_printf.c			\
		lib/ptf/my_put_nbr_abs.c	\
		lib/ptf/my_putnbr_base.c	\
		lib/ptf/my_wrap_base.c		\
		lib/ptf/my_wrap.c			\
		lib/ptf/my_wrap_nbr.c		\
		lib/my/my_strncpy.c			\
		lib/my/my_strcpy.c			\

OBJ	=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(NAME) $(SRC)

clean :
	find -name "*~" -delete , -name "*.o" -delete , -name "#*#" -delete
	rm -f $(OBJ)
	rm -f $(NAME)

fclean : clean
	rm -f $(NAME)

re : fclean all
