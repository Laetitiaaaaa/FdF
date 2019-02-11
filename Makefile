# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llejeune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 15:32:45 by llejeune          #+#    #+#              #
#    Updated: 2019/02/11 14:19:38 by llejeune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = bresenham.c \
	  file_util.c \
	  image.c \
	  main.c \
	  map.c \
	  matrice.c \

OBJ = $(SRC:.c=.o)

FLAG1 = -Wall -Wextra -Werror #-g -fsanitize=address

INCLUDES = -I ./

FLAG3 = -L /usr/local/lib/ \
		 -lmlx \
		 -framework OpenGL \
		 -framework AppKit \

all: $(NAME)

$(NAME): clear $(OBJ)
	make -C ./libft
	cc $(FLAG1) $(INCLUDES) $(OBJ) ./libft/libft.a $(FLAG3) -o $(NAME)

%.o: %.c
	gcc $(FLAG1) $(INCLUDES) -o $@ -c $<

clean:
	make fclean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)


re: fclean $(NAME)


clear: 
	clear

me: 
	cc -g $(FLAG2) *.c ./libft/*.c  $(FLAG3) -o $(NAME)

exe:
	./$(NAME) ./test_maps/ptecarte
	  
.PHONY: all clean fclean re
