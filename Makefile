# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llejeune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 15:32:45 by llejeune          #+#    #+#              #
#    Updated: 2019/02/04 17:34:50 by llejeune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
	  image.c \
	  list.c \
	  matrice.c 

OBJ = $(SRC:.c=.o)

FLAG1 = -Wall -Wextra -Werror

FLAG2 = -I /usr/local/include

FLAG3 = -L /usr/local/lib/ \
		 -lmlx \
		 -framework OpenGL \
		 -framework AppKit \

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	cc -g $(FLAG2) $(OBJ) ./libft/libft.a $(FLAG3) -o $(NAME)

%.o: %.c
	gcc -g $(FLAG1) -o $@ -c $<

clean:
	make fclean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)

me: 
	cc -g $(FLAG2) *.c ./libft/*.c  $(FLAG3) -o $(NAME)
	  
.PHONY: all clean fclean re
