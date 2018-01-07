##
## Copyright (C) 2018 Berthelot Régis (berthelot.regis@gmail.com)
##
## This software is provided 'as-is', without any express or implied
## warranty.  In no event will the authors be held liable for any damages
## arising from the use of this software.
##
## Permission is granted to anyone to use this software for any purpose,
## including commercial applications, and to alter it and redistribute it
## freely, subject to the following restrictions:
##
## 1. The origin of this software must not be misrepresented; you must not
##    claim that you wrote the original software. If you use this software
##    in a product, an acknowledgment in the product documentation would be
##    appreciated but is not required.
## 2. Altered source versions must be plainly marked as such, and must not be
##    misrepresented as being the original software.
## 3. This notice may not be removed or altered from any source distribution.
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wall -Wextra -pedantic -std=gnu90 -Iinclude/

SDL2	=	`pkg-config --cflags --libs sdl2 SDL2_image`

SRC	=	$(addprefix src/,	\
		peekat_core.c		\
		setups.c		\
		main.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	peekat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(SDL2) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

