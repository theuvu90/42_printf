CC = cc
CFLAGS = -Wall -Wextra -Werror	
NAME = libftprintf.a 

SOURCES	=	ft_printf_utils_1.c ft_printf_utils_2.c ft_printf.c				

OBJ =	$(SOURCES:.c=.o)

$(NAME): $(OBJ) 
	ar -rcs $(NAME) $(OBJ) 

.PHONY:	all	clean	fclean	re

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

all: $(NAME)

re:	fclean all
