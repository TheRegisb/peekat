CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wall -Wextra -pedantic -std=gnu90 -Iinclude/

SDL2	=	`pkg-config --cflags --libs sdl2`

SRC	=	$(addprefix src/,	\
		iiw_core.c		\
		setups.c		\
		main.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	iiw

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(SDL2) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
